#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[11];
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    a[n] = a[n - 2];
    int k = 0;
    for (int i = 1; i < n; ++i)
        if ((a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0)
            ++k;
    PutN(k);
}
