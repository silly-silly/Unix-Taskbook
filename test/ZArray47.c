#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    int a[20];
    GetN(&n);
    for (int i = 0; i < n; ++i)
        GetN(&a[i]);
    int k = 1;
    for (int i = 1; i < n; ++i)    
    {
        int k0 = 1;
        for (int j = 0; j < i; ++j)
            if (a[j] == a[i])
                k0 = 0;
        k += k0;
    }
    PutN(k);
}
