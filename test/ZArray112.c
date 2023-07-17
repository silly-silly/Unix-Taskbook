#include "ut1.h"

void Swap(double *a, double *b)
{
    double x = *a;
    *a = *b;
    *b = x;
}

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    for (int k = 1; k < n; ++k)
    {
        for (int i = 0; i < n - k; ++i)  // or i < n - 1
            if (a[i] > a[i + 1])
                Swap(&a[i], &a[i + 1]);
        for (int i = 0; i < n; ++i)
            PutD(a[i]);
    }
}
