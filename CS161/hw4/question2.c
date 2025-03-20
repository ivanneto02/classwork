#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int N = 1500;

int main() {

    int n = N;
    int i, j, k;

    double *a, *b, *c;
    
    time_t start, end;

    /* malloc */
    a = (double *)malloc(N * N * sizeof(double));
    b = (double *)malloc(N * N * sizeof(double));
    c = (double *)malloc(N * N * sizeof(double));

    if (!a || !b || !c) {
        printf("allocate failed!\n");
        exit(-1);
    }

    /* initialization */
    for (i = 0; i < N * N; i++) {
        a[i] = rand() % 1000000 / 1000.0;
        b[i] = rand() % 1000000 / 1000.0;
        c[i] = rand() % 1000000 / 1000.0;
    }

    /*simple ijk version*/
    start = clock();
    for (i = 0; i < N; i += 1)
        for (j = 0; j < N; j += 1)
            for (k = 0; k < N; k += 1)
                c[i * N + j] = c[i * N + j] + a[i * n + k] * b[k * n + j];
    end = clock();

    printf("Time taken (ijk version): %.6lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    /*simple ikj version*/
    start = clock();
    for (i = 0; i < N; i += 1)
        for (k = 0; k < N; k += 1)
            for (j = 0; j < N; j += 1)
                c[i * N + j] = c[i * N + j] + a[i * n + k] * b[k * n + j];
    end = clock();

    printf("Time taken (ikj version): %.6lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    /*simple kji version*/
    start = clock();
    for (k = 0; k < N; k += 1)
        for (j = 0; j < N; j += 1)
            for (i = 0; i < N; i += 1)
                c[i * N + j] = c[i * N + j] + a[i * n + k] * b[k * n + j];
    end = clock();

    printf("Time taken (kji version): %.6lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}