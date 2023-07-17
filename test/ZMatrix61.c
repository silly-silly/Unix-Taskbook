#include "ut1.h"

int main(int argc, char *argv[])
{
    int m, n, k;
    double a[10][10];
    GetN(&m);
    GetN(&n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            GetD(&a[i][j]);
    GetN(&k);

    for (int i = k + 1; i < m; ++i)
        for (int j = 0; j < n; ++j)
            a[i - 1][j] = a[i][j];
    --m;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            PutD(a[i][j]);
}
