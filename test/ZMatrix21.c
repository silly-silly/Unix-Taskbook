#include "ut1.h"

int main(int argc, char *argv[])
{
    int m, n;
    double a[10][10];
    GetN(&m);
    GetN(&n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            GetD(&a[i][j]);
    for (int i = 0; i < m; i += 2)
    {
        double sum = 0;
        for (int j = 0; j < n; ++j)
            sum += a[i][j];
        PutD(sum / n);
    }
}
