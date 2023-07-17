#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    int a[20];
    a[0] = 2;
    for (int i = 1; i < n; ++i)
        a[i] = a[i-1] * 2;
    for (int i = 0; i < n; ++i)
        PutN(a[i]);
}
