/* 
 * tsh - A tiny shell program with job control
 * 
 * Ivan Neto - ineto001
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Misc manifest constants */
#define MAXLINE    1024   /* max line size */
#define MAXARGS     128   /* max args on a command line */
#define MAXJOBS      16   /* max jobs at any point in time */
#define MAXJID    1<<16   /* max job ID */

/* Job states */
#define UNDEF 0 /* undefined */
#define FG 1    /* running in foreground */
#define BG 2    /* running in background */
#define ST 3    /* stopped */

/* 
 * Jobs states: FG (foreground), BG (background), ST (stopped)
 * Job state transitions and enabling actions:
 *     FG -> ST  : ctrl-z
 *     ST -> FG  : fg command
 *     ST -> BG  : bg command
 *     BG -> FG  : fg command
 * At most 1 job can be in the FG state.
 */

/* Global variables */
extern char **environ;      /* defined in libc */
char prompt[] = "tsh> ";    /* command line prompt (DO NOT CHANGE) */
int verbose = 0;            /* if true, print additional output */
int nextjid = 1;            /* next job ID to allocate */
char sbuf[MAXLINE];         /* for composing sprintf messages */

struct job_t {              /* The job struct */
    pid_t pid;              /* job PID */
    int jid;                /* job ID [1, 2, ...] */
    int state;              /* UNDEF, BG, FG, or ST */
    char cmdline[MAXLINE];  /* command line */
};
struct job_t jobs[MAXJOBS]; /* The job list */
/* End global variables */

/* Function prototypes */

/* Here are the functions that you will implement */
void eval(char *cmdline);          // Main routine that parses and interprets the command line. [70 lines]
int builtin_cmd(char **argv);      // Recognizes and interprets the built-in commands: `quit`, `fg`, `bg`, and `jobs` [25 lines]
void do_bgfg(char **argv);         // Implements the `bg` and `fg` built-in commands [50 lines]
void waitfg(pid_t pid);            // Waits for a foreground job to complete. [20 lines]

void sigchld_handler(int sig);     // Catches SIGCHILD signals. [80 lines]
void sigtstp_handler(int sig);     // Catches SIGTSTP (ctrl-z) signals. [15 lines]
void sigint_handler(int sig);      // Catches SIGINT (ctrl-c) signals. [15 lines]


/* Here are helper routines that we've provided for you */
int parseline(const char *cmdline, char **argv);                        // Parse the command line and build the argv array.
void sigquit_handler(int sig);                                          // The driver program can gracefully terminate the program

void clearjob(struct job_t *job);                                       // Clear the entries in a job struct
void initjobs(struct job_t *jobs);                                      // initjobs - Initialize the job list
int maxjid(struct job_t *jobs);                                         // Returns largest allocated job ID
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline);    // Add a job to the job list
int deletejob(struct job_t *jobs, pid_t pid);                           // Deletes job from the list of jobs, given pid_t pid
pid_t fgpid(struct job_t *jobs);                                        // Return PID of current foreground job, 0 if no such job          
struct job_t *getjobpid(struct job_t *jobs, pid_t pid);                 // Find a job (by PID) on the job list
struct job_t *getjobjid(struct job_t *jobs, int jid);                   // Find a job (by JID) on the job list
int pid2jid(pid_t pid);                                                 // Map process ID to job ID
void listjobs(struct job_t *jobs);                                      // Print the job list

void usage(void);                                                       // print a help message
void unix_error(char *msg);                                             // unix-style error routine
void app_error(char *msg);                                              // application-style error routine
typedef void handler_t(int);                                            // I believe this defines a type called handler_t which takes in an integer
handler_t *Signal(int signum, handler_t *handler);                      // wrapper for the sigaction function

/*
 * main - The shell's main routine 
 */
int main(int argc, char **argv) 
{
    char c;
    char cmdline[MAXLINE];
    int emit_prompt = 1; /* emit prompt (default) */

    /* Redirect stderr to stdout (so that driver will get all output
     * on the pipe connected to stdout) */
    dup2(1, 2);

    /* Parse the command line */
    while ((c = getopt(argc, argv, "hvp")) != EOF) {
        switch (c) {
            case 'h':             /* print help message */
                usage();
                break;
            case 'v':             /* emit additional diagnostic info */
                verbose = 1;
                break;
            case 'p':             /* don't print a prompt */
                emit_prompt = 0;  /* handy for automatic testing */
                break;
            default:
                usage();
                break;
	    }
    }

    /* Install the signal handlers */

    /* These are the ones you will need to implement */
    Signal(SIGINT,  sigint_handler);   /* ctrl-c */
    Signal(SIGTSTP, sigtstp_handler);  /* ctrl-z */
    Signal(SIGCHLD, sigchld_handler);  /* Terminated or stopped child */

    /* This one provides a clean way to kill the shell */
    Signal(SIGQUIT, sigquit_handler); 

    /* Initialize the job list */
    initjobs(jobs);

    /* Execute the shell's read/eval loop */
    while (1) {
        
        /* Read command line */
        if (emit_prompt) {
            printf("%s", prompt);
            fflush(stdout);
        }
        if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin))
            app_error("fgets error");
        if (feof(stdin)) { /* End of file (ctrl-d) */
            fflush(stdout);
            exit(0);
        }

        /* Evaluate the command line */
        eval(cmdline);
        fflush(stdout);
        fflush(stdout);
    } 

    exit(0); /* control never reaches here */
}
  
/* 
 * eval - Evaluate the command line that the user has just typed in
 * 
 * If the user has requested a built-in command (quit, jobs, bg or fg)
 * then execute it immediately. Otherwise, fork a child process and
 * run the job in the context of the child. If the job is running in
 * the foreground, wait for it to terminate and then return.  Note:
 * each child process must have a unique process group ID so that our
 * background children don't receive SIGINT (SIGTSTP) from the kernel
 * when we type ctrl-c (ctrl-z) at the keyboard.
*/
void eval(char* cmdline) 
{

    // will store the vector containing the different parts of
    // the argument vector.
    char* argv[MAXARGS];

    // This stores the mask to block and unblock certain signals
    sigset_t mask;

    // parseline returns whether we want to run in the backgruond.
    // That's what bg_flag is for.
    int bg_flag = parseline(cmdline, argv);

    // Holds either NULL or the command itself
    char* command = argv[0];

    // Detects empty lines, in which case we want to do nothing
    if (command == NULL) {
        return;
    }

    // Only execute our command as a separate process if it's not a built-in command,
    // otherwise it will be immediately executed within builtin_cmd.
    if (!builtin_cmd(argv)) { 

        // We must block SIGCHLD, SIGTSTP, and SIGINT in order to prevent
        // race conditions...

        /* BLOCKING EVERY SIGNAL */

        // makes &mask be the empty set.
        // We will add every signal to the mask
        if (sigemptyset(&mask) < 0) {
            unix_error("sigemptyset error");
        }

        // Adding all the signals to the mask
        if (sigaddset(&mask, SIGCHLD)) {
            unix_error("sigaddset error");
        }
        if (sigaddset(&mask, SIGINT)) {
            unix_error("siggaddset error");
        }
        if (sigaddset(&mask, SIGTSTP)) {
            unix_error("sigaddset error");
        }

        // Change blocked signals based on &mask
        if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0) {
            unix_error("sixprocmask error");
        }

        /* DONE BLOCKING SIGNALS */

        // At this point, we know no built-in commands were called.
        // We must fork() into a child and execute the program there.
        int fork_pid = fork();

        // In the case that fork fails
        if (fork_pid < 0) {
            unix_error("fork error");
        }

        // This will check whether we are in child
        if (fork_pid == 0) { // Currently in child

            // Unblock the signals since we are now in child!
            // Thus we ARE allowed to call the signals
            sigprocmask(SIG_UNBLOCK, &mask, NULL);

            // We have to give new jobs a group ID.
            int setprocessid_ret = setpgid(0, 0);

            // An error occurred giving the child process a group id
            if (setprocessid_ret < 0) {
                unix_error("setpgid error");
            }

            // execute the program we want!
            int exec_ret = execve(command, argv, environ);

            if (exec_ret < 0) {
                printf("%s: Command not found\n", argv[0]);
                exit(0);
            }

        }

        // Checks if we are currently in parent
        else { // Currently in parent

            // We must add the foreground job to the job list and set its status as FG or BG
            addjob(jobs, fork_pid, (bg_flag ? BG : FG), cmdline);

            // We need handlers to run correctly so we unblock the signals.
            sigprocmask(SIG_UNBLOCK, &mask, NULL);

            // Only wait if we run child in foreground
            if (!bg_flag) {
                waitfg(fork_pid);
            }
            else { // child must run in background
                // Let the user know a background process is happening
                printf("[%d] (%d) %s", pid2jid(fork_pid), fork_pid, cmdline);
            }
        }
    }
}

/* 
 * parseline - Parse the command line and build the argv array.
 * 
 * Characters enclosed in single quotes are treated as a single
 * argument.  Return true if the user has requested a BG job, false if
 * the user has requested a FG job.  
 */
int parseline(const char *cmdline, char **argv) 
{
    static char array[MAXLINE]; /* holds local copy of command line */
    char *buf = array;          /* ptr that traverses command line */
    char *delim;                /* points to first space delimiter */
    int argc;                   /* number of args */
    int bg;                     /* background job? */

    strcpy(buf, cmdline);
    buf[strlen(buf)-1] = ' ';  /* replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* ignore leading spaces */
	buf++;

    /* Build the argv list */
    argc = 0;
    if (*buf == '\'') {
        buf++;
        delim = strchr(buf, '\'');
    }
    else {
	    delim = strchr(buf, ' ');
    }

    while (delim) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) {/* ignore spaces */
            buf++;
        }

        if (*buf == '\'') {
            buf++;
            delim = strchr(buf, '\'');
        }
        else {
            delim = strchr(buf, ' ');
        }

    }
    argv[argc] = NULL;
    
    if (argc == 0) { /* ignore blank line */
	    return 1;
    }

    /* should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0) {
	    argv[--argc] = NULL;
    }

    return bg;
}

/* 
 * builtin_cmd - If the user has typed a built-in command then execute
 *    it immediately.  
 */
int builtin_cmd(char **argv) 
{

    // Stores the specific command we just ran
    char* command = argv[0];

    // Here we check all four built-in commands:
    // quit, jobs, bg, fg. I put bg and fg at the end
    // because those go hand in hand
    if (!strcmp(command, "quit")) {
        exit(0); // exit the shell, nothing more to do because we are quitting
    }
    else if (!strcmp(command, "jobs")) {
        listjobs(jobs); // lists every job we are running.
        return 1;
    }
    else if (!strcmp(command, "bg") || !strcmp(command, "fg")) {
        do_bgfg(argv); // function determines whether bg or fg is called, and executes it
        return 1;
    }
    else if (!strcmp(command, "&")) {
        return 1; // Do nothing, ignore singleton "&" according to lab tutorial
    }

    return 0;     /* not a builtin command */
}

/* 
 * do_bgfg - Execute the builtin bg and fg commands
 */
void do_bgfg(char **argv) 
{

    // background flag, tracks whether do_bgfg should do
    // bg or fg.
    int bg = 0;
    
    // job flag. We assume the user will pass in a process, but
    // if not we set this flag to 1.
    int job_flag = 0;

    // Ignore if we have NULL
    if (argv[1] == NULL) {
        printf("%s command requires PID or %%jobid argument\n", argv[0]);
        return;
    }

    // We successfully identify a job
    if (!isdigit(argv[1][0])) {
        job_flag = 1;
    }

    // Check validity of a process
    if (!job_flag && !isdigit(argv[1][0])) {
        printf("%s: argument must be a PID or %%jobid\n", argv[0]);
        return;
    }

    // Check validity of a job
    if (job_flag && !isdigit(argv[1][1])) {
        printf("%s: argument must be a PID or %%jobid\n", argv[0]);
        return;
    }

    // Check which command we are using
    char* command = argv[0];
    if (!strcmp(command, "bg")) {
        bg = 1; // set the background flag to true
    }

    // pid and jid keep the argument that the user
    // passes to move the process with jid or pid, depending
    // on their choice since we want to handle both.
    pid_t pid;
    int jid;

    // Decides whether to grab jid or pid, methods are different
    if (job_flag) {
        jid = atoi(&argv[1][1]); // Grabs from argv[1][1] to the end of the number.
    }
    else {
        pid = atoi(argv[1]); // Grabs only argv[1] because we assume that is a number.
    }

    // We need to find the pid structure so we can
    // change its state
    struct job_t* job;

    // Decides whether to grab from jid or pid
    if (job_flag) {
        job = getjobjid(jobs, jid); // get the job given jid
    }
    else {
        job = getjobpid(jobs, pid); // get the job given pid
    }

    // The job we are being requested does not exist
    if (!job && (job_flag)) {
        printf("%%%d: No such job\n", jid);
        return;
    }
    else if (!job && (!job_flag)) {
        printf("(%d): No such process\n", pid);
        return;
    }

    // change the state of the curr_job
    if (bg) {
        job->state = BG;
    }
    else {
        job->state = FG;
    }
    
    // Send SIGCONT signal to the process in order to
    // restart it. YES SIR SEND IT.
    if (kill(-(job->pid), SIGCONT) < 0) {
        if (!strcmp(command, "fg")) {
            unix_error("kill (fg) error");
        }
        else {
            unix_error("kill (bg) error");
        }
    }

    // If the command is fg, we need to wait on
    // the console by calling waitfg
    if (!bg) {
        // wait until the foreground process ends, then we can
        // continue with the console.
        waitfg(job->pid);
    }
    else {
        printf("[%d] (%d) %s", job->jid, job->pid, job->cmdline);
    }
}

/* 
 * waitfg - Block until process pid is no longer the foreground process
 */
void waitfg(pid_t pid)
{

    // Grab the job identified by pid
    struct job_t* job = getjobpid(jobs, pid);

    // If !job, then we know that the job has already been reaped, we don't
    // want to wait for a non-job...
    if (!job) {
        return;
    }


    // While the pid of the job is 1, and it is in the foreground state,
    // we want to create a busy loop that sleeps. This will let the foreground
    // process finish.
    while(job->pid == pid && job->state == FG) {
        sleep(1);
    }

    if (verbose) {
        printf("waitfg: Process (%d) no longer the fg process\n", pid);
    }
}

/*****************
 * Signal handlers
 *****************/

/* 
 * sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
 *     a child job terminates (becomes a zombie), or stops because it
 *     received a SIGSTOP or SIGTSTP signal. The handler reaps all
 *     available zombie children, but doesn't wait for any other
 *     currently running children to terminate.  
 */
void sigchld_handler(int sig) 
{

    if (verbose) {
        printf("sigchld_handler: entering\n");
    }

    pid_t c_pid; // stores pid for child
    int c_jid; // stores jid for child
    int status; // to pass into waitpid

    if (verbose) {
        printf("sigchld_handler: entering\n");
    }

    // we wait for every STOPPED child to be reaped
    // waitpid(pid, status*, options)
    // pid = -1 indicates waiting for all child processes
    // &status saves the status in status
    // WNOHANG indicates we only wait for the children that are running 
    // The while loop does this multiple times, untill all zombie children
    // are reaped.
    while ( (c_pid = waitpid(-1, &status, WNOHANG|WUNTRACED) ) > 0) {

        struct job_t* job;

        // Check if the process c_pid was STOPPED
        if (WIFSTOPPED(status)) {

            // Grab the current zombie job. Remember, c_pid contains pid from zombie child
            // that was acquired from waitpid.
            job = getjobpid(jobs, c_pid);

            if (!job) {
                printf("Lost track of (%d)\n", c_pid);
                return;
            }

            job->state = ST;

            // Print out what [jid] (pid), and the signal that stopped it. WSTOPSIG gives the signal that
            // stopped given the particular status we captured in `status`.
            fprintf(stdout, "Job [%d] (%d) stopped by signal %d\n", pid2jid(c_pid), c_pid, WSTOPSIG(status));
        }

        // Otherwise, the process was TERMINATED by an uncaught signal. If the process was terminated by an
        // uncaught signal, we MUST delete it from the joblist. There is no setting it to ST because it has
        // been fully terminated.
        else if (WIFSIGNALED(status)) {

            // get jid from pid, we will use it to print out information for the user
            c_jid = pid2jid(c_pid);

            // We save the return value to check for failure
            int delete_ret = deletejob(jobs, c_pid);

            // Check if we failed to delete c_pid
            if (!delete_ret) {
                return;
            }

            if (verbose) {
                printf("sigchld_handler: Job [%d] (%d) deleted\n", c_jid, c_pid);
            }

            // Here we know that deletejob succeeded, thus we print out information for the user
            // about which [jid], and (pid) was terminated by the termination signal identified by
            // status variable that we got from the while loop waitpid.
            fprintf(stdout, "Job [%d] (%d) terminated by signal %d\n", c_jid, c_pid, WTERMSIG(status));
        }

        // Otherwise, it is possible that the child process terminated normally, without having been sent a
        // signal to stop. The SIGCHLD signal is still sent to the parent process anyway, even if no manual
        // signal was sent.
        else if (WIFEXITED(status)) { // This means the process is TERMINATED, we must do the same.

            // get jid from pid, we will use it to print out information for the user
            c_jid = pid2jid(c_pid);

            // We save the return value to check for failure
            int delete_ret = deletejob(jobs, c_pid);

            // Check if we failed to delete c_pid
            if (!delete_ret) {
                return;
            }

            if (verbose) {
                printf("sigchld_handler: Job [%d] (%d) deleted\n", c_jid, c_pid);
            }

            if (verbose) {
                printf("sigchld_handler: Job [%d] (%d) terminates OK (status %d)\n", c_jid, c_pid, WEXITSTATUS(status));
            }

            // Since no signal was sent to stop the process, we don't want to print
            // a status message to the user just because. Thus we don't print anything here.
        }
        else {
            unix_error("waitpid error");
        }

    } // Terminate the while loop because there were no children or there were no zombie children
    
    // Here there's the possibility that there are children but my SIGCHLD handler failed to do its job
    // so I want to print an error message

    if (!((c_pid == 0) || (c_pid == -1 && errno == ECHILD))) {
        unix_error("sigchld_handler wait error");
    }

    if (verbose) {
        printf("sigchld_handler: exiting\n");
    }
}

/* 
 * sigint_handler - The kernel sends a SIGINT to the shell whenever the
 *    user types ctrl-c at the keyboard.  Catch it and send it along
 *    to the foreground job.  
 */
void sigint_handler(int sig) 
{

    if (verbose) {
        printf("sigint_handler: entering\n");
    }

    // Saves the PID of the current foreground process
    pid_t foreground_pid = fgpid(jobs);

    // fgpid returns 0 when there are no foreground processes
    if (foreground_pid <= 0) {
        return; // do nothing, signal has no effect when
        // there are no foreground processes
    }

    // Calls the kill function with pid = foreground_process_pid,
    // and signal = sig because sig already contains SIGINT.
    if (kill(-foreground_pid, SIGINT) < 0) {
        unix_error("kill (sigint) error");
    }

    if (verbose) {
        printf("sigint_handler: Job (%d) killed\n", foreground_pid);
    }

    if (verbose) {
        printf("sigint_handler: exiting\n");
    }

}

/*
 * sigtstp_handler - The kernel sends a SIGTSTP to the shell whenever
 *     the user types ctrl-z at the keyboard. Catch it and suspend the
 *     foreground job by sending it a SIGTSTP.  
 */
void sigtstp_handler(int sig) 
{

    if (verbose) {
        printf("sigstp_handler: entering\n");
    }

    // Saves the PID of the current foreground process
    pid_t foreground_pid = fgpid(jobs);

    // fgpid returns 0 when there are no foreground processes
    if (foreground_pid <= 0) {
        return; // do nothing, signal has no effect when
        // there are no foreground processes
    }

    // Calls the kill function with pid = foreground_process_pid,
    // and signal = sig because sig already contains SIGINT.
    if (kill(-foreground_pid, SIGTSTP) < 0) {
        unix_error("kill (tstp) error");
    }

    if (verbose) {
        printf("sigtstp_handler: Job [%d] (%d) stopped\n", pid2jid(foreground_pid), foreground_pid);
    }

    if (verbose) {
        printf("sigstp_handler: entering\n");
    }

}

/*********************
 * End signal handlers
 *********************/

/***********************************************
 * Helper routines that manipulate the job list
 **********************************************/

/* clearjob - Clear the entries in a job struct */
void clearjob(struct job_t *job) {
    job->pid = 0;
    job->jid = 0;
    job->state = UNDEF;
    job->cmdline[0] = '\0';
}

/* initjobs - Initialize the job list */
void initjobs(struct job_t *jobs) {
    int i;

    for (i = 0; i < MAXJOBS; i++) {
	    clearjob(&jobs[i]);
    }
}

/* maxjid - Returns largest allocated job ID */
int maxjid(struct job_t *jobs) 
{
    int i, max=0;

    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].jid > max) {
	    max = jobs[i].jid;
    }
    return max;
}

/* addjob - Add a job to the job list */
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline) 
{
    int i;
    
    if (pid < 1)
	return 0;

    for (i = 0; i < MAXJOBS; i++) {
        if (jobs[i].pid == 0) {
            jobs[i].pid = pid;
            jobs[i].state = state;
            jobs[i].jid = nextjid++;
            if (nextjid > MAXJOBS)
            nextjid = 1;
            strcpy(jobs[i].cmdline, cmdline);
            if(verbose){
                printf("Added job [%d] %d %s\n", jobs[i].jid, jobs[i].pid, jobs[i].cmdline);
                }
                return 1;
        }
    }
    printf("Tried to create too many jobs\n");
    return 0;
}

/* deletejob - Delete a job whose PID=pid from the job list */
int deletejob(struct job_t *jobs, pid_t pid) 
{
    int i;

    if (pid < 1)
	return 0;

    for (i = 0; i < MAXJOBS; i++) {
        if (jobs[i].pid == pid) {
            clearjob(&jobs[i]);
            nextjid = maxjid(jobs)+1;
            return 1;
        }
    }
    return 0;
}

/* fgpid - Return PID of current foreground job, 0 if no such job */
pid_t fgpid(struct job_t *jobs) {
    int i;

    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].state == FG)
	    return jobs[i].pid;

    return 0;
}

/* getjobpid  - Find a job (by PID) on the job list */
struct job_t *getjobpid(struct job_t *jobs, pid_t pid) {
    int i;

    if (pid < 1)
	return NULL;
    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].pid == pid)
	    return &jobs[i];
    return NULL;
}

/* getjobjid  - Find a job (by JID) on the job list */
struct job_t *getjobjid(struct job_t *jobs, int jid) 
{
    int i;

    if (jid < 1)
	return NULL;
    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].jid == jid)
	    return &jobs[i];
    return NULL;
}

/* pid2jid - Map process ID to job ID */
int pid2jid(pid_t pid) 
{
    int i;

    if (pid < 1) {
	    return 0;
    }

    for (i = 0; i < MAXJOBS; i++) {
	    if (jobs[i].pid == pid) {
            return jobs[i].jid;
        }
    }
    
    return 0;
}

/* listjobs - Print the job list */
void listjobs(struct job_t *jobs) 
{
    int i;
    
    for (i = 0; i < MAXJOBS; i++) {
	if (jobs[i].pid != 0) {
	    printf("[%d] (%d) ", jobs[i].jid, jobs[i].pid);
	    switch (jobs[i].state) {
		case BG: 
		    printf("Running ");
		    break;
		case FG: 
		    printf("Foreground ");
		    break;
		case ST: 
		    printf("Stopped ");
		    break;
	    default:
		    printf("listjobs: Internal error: job[%d].state=%d ", 
			   i, jobs[i].state);
	    }
	    printf("%s", jobs[i].cmdline);
	}
    }
}
/******************************
 * end job list helper routines
 ******************************/


/***********************
 * Other helper routines
 ***********************/

/*
 * usage - print a help message
 */
void usage(void) 
{
    printf("Usage: shell [-hvp]\n");
    printf("   -h   print this message\n");
    printf("   -v   print additional diagnostic information\n");
    printf("   -p   do not emit a command prompt\n");
    exit(1);
}

/*
 * unix_error - unix-style error routine
 */
void unix_error(char *msg)
{
    fprintf(stdout, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

/*
 * app_error - application-style error routine
 */
void app_error(char *msg)
{
    fprintf(stdout, "%s\n", msg);
    exit(1);
}

/*
 * Signal - wrapper for the sigaction function
 */
handler_t *Signal(int signum, handler_t *handler) 
{
    struct sigaction action, old_action;
 
    action.sa_handler = handler;  
    sigemptyset(&action.sa_mask); /* block sigs of type being handled */
    action.sa_flags = SA_RESTART; /* restart syscalls if possible */

    if (sigaction(signum, &action, &old_action) < 0)
	unix_error("Signal error");
    return (old_action.sa_handler);
}

/*
 * sigquit_handler - The driver program can gracefully terminate the
 *    child shell by sending it a SIGQUIT signal.
 */
void sigquit_handler(int sig) 
{
    printf("Terminating after receipt of SIGQUIT signal\n");
    exit(1);
}



