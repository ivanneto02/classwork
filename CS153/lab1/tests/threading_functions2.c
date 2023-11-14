#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// packed argument values
typedef struct { int a; int b; } myarg_t;

// packed return values
typedef struct { int x; int y; } myret_t;

// thread function to execute once thread is joined
void *mythread(void *arg) {

    // allocate data on the heap for ret values
    myret_t *rvals = malloc( sizeof(myret_t) );

    rvals->x = 3;
    rvals->y = 4;

    return (void *) rvals;
}

int main(int argc, char *argv[]) {

    pthread_t p;
    myret_t *rvals;
    myarg_t args = { 10, 20 };
    
    pthread_create(&p, NULL, mythread, &args);

    pthread_join(p, (void **) &rvals);

    printf("returned %d %d\n", rvals->x, rvals->y);
    
    free(rvals);
    
    return 0;
}
