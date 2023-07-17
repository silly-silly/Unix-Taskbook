#include "ut1.h"

int main(int argc, char *argv[])
{
    int m, n, k;
    GetN(&m);
    GetN(&n);

    double** a = malloc(n * sizeof(double*));  // by columns!
    for (int j = 0; j < n; ++j)
        a[j] = malloc(m * sizeof(double));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            GetD(&a[j][i]);  // !!!
    GetN(&k);

    for (int j = k + 1; j < n; ++j)
        a[j - 1] = a[j];
    --n;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            PutD(a[j][i]);  // !!!

    for (int j = 0; j < n; ++j)
        free(a[j]);
    free(a);    

}
