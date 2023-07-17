#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    int k, l;
    GetN(&k);
    GetN(&l);
    for (int i = 0; i < (l - k + 1) / 2; ++i)
    {
        double x = a[k + i];
        a[k + i] = a[l - i];
        a[l - i] = x;
    }

    for (int i = 0; i < n; ++i)
        PutD(a[i]);
}
