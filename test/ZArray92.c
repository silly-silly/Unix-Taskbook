#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    int a[10];
    for (int i = 0; i < n; ++i)
        GetN(&a[i]);
    for (int i = n - 1; i >= 0; --i)
        if (a[i] % 2 != 0)
        {
            for (int j = i + 1; j < n; ++j)
                a[j - 1] = a[j];
            --n;
        }
    PutN(n);
    for (int i = 0; i < n; ++i)
        PutN(a[i]);
}
