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
    for (int j = 0; j < n; ++j)            
        PutD(a[k][j]);
}
