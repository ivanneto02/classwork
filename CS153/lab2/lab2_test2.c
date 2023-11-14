#include "types.h"
#include "user.h"

int Inheritance(void);

int main(int argc, char *argv[])
{
    Inheritance();

    exit();
}    
      
int Inheritance(void){
    
    // Use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority. All processes have a default priority of 10
    // You can use your own priority range/value setup

    int pid, ret_pid;
    int j,k;

    printf(1, "Testing the priority inheritance and setpriority system call:\n");
    printf(1, "Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, " - The parent processes will switch to priority 3\n\n");

    // set parent's priority to 25
    set_priority(3);
    
    // set priority
    pid = fork();
    if (pid > 0) {

    } else if ( pid == 0) {
        printf(1, " > Hello! this is child# %d and I will change my priority to %d\n", getpid(), 10);
        set_priority(10);
        for (j = 0; j < 50000; j++) {
            asm("nop");
            for(k = 0; k < 10000; k++) {
                asm("nop"); 
            }
        }
        printf(1, " > Child #%d with priority %d has finished! \n", getpid(), 10);
        exit();
    } else {
        printf(2," \n Error fork() \n");
        exit();
    }

    if(pid > 0) {
        ret_pid = wait();
        printf(1, " > This is the parent: child with PID# %d has finished\n", ret_pid);
    }
			
    return 0;
}

