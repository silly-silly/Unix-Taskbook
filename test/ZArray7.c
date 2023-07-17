#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    double a[20];
    GetN(&n);
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    for (int i = 0; i < n; ++i)
        PutD(a[n - 1 - i]);
}
