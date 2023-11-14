#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;

// define a lock_t data type
// with `flag` : int member
typedef struct __lock_t {
    pthread_mutex_t lock;
    int flag;
} lock_t;

int TestAndSet(int *old_ptr, int new) {
    int old = *old_ptr;
    *old_ptr = new;
    return old;
}

// initializes the lock variable
void init(lock_t* lock) {
    // 0: lock is available, 1: lock is held
    lock->flag = 0; // init to 0
}

// locks down critical section so only
// one thread can access it
void lock(lock_t* lock) {
    while(TestAndSet(&lock->flag, 1) == 1) {
        // wait until other thread unlocks       
    }
    pthread_mutex_lock(&lock->lock);
}

// unlocks critical section so
// new thread can access it now
void unlock(lock_t* lock) {
    lock->flag = 0;
    pthread_mutex_unlock(&lock->lock);
}

// mythread()
//
// Simply adds 1 to counter repeatedly, in a loop
// No, this is not how you would add 10,000,000 to
// a counter, but it shows the problem nicely.
//
void *mythread(void *arg) {
    printf("%s: begin\n", (char *) arg);
    int i;
    lock_t mylock;
    pthread_mutex_t loclock;
    mylock.lock = loclock;
    int rc = pthread_mutex_init(&(mylock.lock), NULL);
    lock(&mylock);
    for (i = 0; i < 1e7; i++) {
        counter = counter + 1;
    }
    unlock(&mylock);
    printf("%s: done\n", (char *) arg);
    return NULL;
}

// main()
//
// Just launches two threads (pthread_create)
// and then waits for them (pthread_join)
//
int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    printf("main: begin (counter = %d)\n", counter);
    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");

    // join waits for the threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("main: done with both (counter = %d)\n", counter);
    return 0;
}