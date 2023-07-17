#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    for (int i = n - 2; i >= 0; --i)
        a[i + 1] = a[i];
    a[0] = 0;
    for (int i = 0; i < n; ++i)
        PutD(a[i]);
}
