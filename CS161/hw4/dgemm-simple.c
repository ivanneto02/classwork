#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int N = 2048;

int main()
{
    int n = N;
    int i, j, k, i1, j1, k1;
    double *a, *b, *c, *cc;
    time_t start, end;

    /* malloc */
    a = (double *)malloc(N * N * sizeof(double));
    b = (double *)malloc(N * N * sizeof(double));
    c = (double *)malloc(N * N * sizeof(double));
    cc = (double *)malloc(N * N * sizeof(double));
    if (!a || !b || !c || !cc)
    {
        printf("allocate failed!\n");
        exit(-1);
    }
    /* initialization */
    for (i = 0; i < N * N; i++)
    {
        a[i] = rand() % 1000000 / 1000.0;
        b[i] = rand() % 1000000 / 1000.0;
        c[i] = rand() % 1000000 / 1000.0;
        cc[i] = c[i];
    }

    /*simple ijk version*/
    start = clock();
    for (i = 0; i < N; i += 1)
        for (j = 0; j < N; j += 1)
            for (k = 0; k < N; k += 1)
                c[i * N + j] += a[i * n + k] * b[k * n + j];

    end = clock();
    printf("Time for optimized version: %.6lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    /* check error with ijk version */
    double error = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                cc[i * n + j] += a[i * n + k] * b[k * n + j];

    for (i = 0; i < N * N; i++)
        error += (c[i] - cc[i]) * (c[i] - cc[i]);
    printf("Numerical errors introduced by optimization = %e\n", error);
}