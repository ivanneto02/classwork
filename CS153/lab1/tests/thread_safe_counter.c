#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct __counter_t {
    int                 value;
    pthread_mutex_t     lock;
} counter_t;

void init(counter_t* c) {
    c->value = 0;
    pthread_mutex_init(&(c->lock), NULL);
}

void increment(counter_t* c) {
    pthread_mutex_lock(&c->lock);
    c->value++;
    pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t* c) {
    pthread_mutex_lock(&c->lock);
    c->value--;
    pthread_mutex_unlock(&c->lock);
}

int get(counter_t* c) {
    pthread_mutex_lock(&c->lock);
    int rc = c->value;
    pthread_mutex_unlock(&c->lock);
    return c->value;
}

int main(int argc, char *argv[]) {

    counter_t* myCounter = (counter_t*) malloc(sizeof(counter_t) + 1);

    init(myCounter);

    for (int i = 0; i < 1e6; i++) {
        increment(myCounter);
    }

    printf("Value at the end: %d\n", myCounter->value);
    
    return 0;
}
