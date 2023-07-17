#include "ut1.h"
#include <float.h>

void Swap(double *a, double *b)
{
    double x = *a;
    *a = *b;
    *b = x;
}

int main(int argc, char *argv[])
{
    int m, n;
    double a[10][10];
    GetN(&m);
    GetN(&n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            GetD(&a[i][j]);

    double min[10];
    for (int i = 0; i < m; ++i)
    {
        min[i] = DBL_MAX;
        for (int j = 0; j < n; ++j)
            if (a[i][j] < min[i])
                min[i] = a[i][j];
    }
    
    for (int k = 1; k < m; ++k)
        for (int i = 0; i < m - k; ++i)
            if (min[i] < min[i + 1])
            {
                Swap(&min[i], &min[i + 1]);
                for (int j = 0; j < n; ++j)
                    Swap(&a[i][j], &a[i + 1][j]);
            }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            PutD(a[i][j]);
}
