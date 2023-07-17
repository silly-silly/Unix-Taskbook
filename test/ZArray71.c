#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    for (int i = 0; i < n / 2; ++i)
    {
        double x = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = x;
    }

    for (int i = 0; i < n; ++i)
        PutD(a[i]);

}
