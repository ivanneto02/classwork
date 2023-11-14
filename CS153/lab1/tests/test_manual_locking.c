#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;

int enter[2] = {0, 0};
int turn = 0;

void* thread0() {

    printf("    thread0: start\n");

    for (int i = 0; i < 1e6; i++) {

        /* LOCKING START */
        enter[0] = 1;
        while (enter[1]) {

            // if not my turn, temp wait till turn
            if (turn != 0) {
                enter[0] = 0;
                while (turn != 0);
                enter[0] = 1;
            }

        }
        /* LOCKING START */

        // critical section
        counter = counter + 1;

        /* LOCKING END */
        turn = 1;
        enter[0] = 0;
        /* LOCKING END */
    }
}

void* thread1() {

    printf("    thread1: start\n");

    for (int i = 0; i < 1e6; i++) {

        /* LOCKING START */
        enter[1] = 1;
        while (enter[0]) {

            // if not my turn, temp wait till turn
            if (turn != 1) {
                enter[1] = 0;
                while (turn != 1);
                enter[1] = 1;
            }

        }
        /* LOCKING END */

        // critical section
        counter = counter + 1;

        /* LOCKING END */
        turn = 0;
        enter[1] = 0;
        /* LOCKING END */

    }
}

int main(int argc, char** argv) {

    printf("main: start\n");

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, (void*) thread0, NULL);
    pthread_create(&t2, NULL, (void*) thread1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("main: end\n");

    printf("final value of counter: %d\n", counter);

    return 0;
}