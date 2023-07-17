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
        PutD(a[i]);
        PutD(a[n - 1 - i]);
    }
    if (n % 2 != 0)
        PutD(a[n / 2]);
}
