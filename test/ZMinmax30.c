#include "ut1.h"
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[])
{
    int n, a;
    GetN(&n);
    GetN(&a);
    int amax = a, kmin = INT_MAX, k = 1;
    for (int i = 1; i < n; ++i)
    {
        int b;
        GetN(&b);
        if (b > amax)
        {
            amax = b;
            kmin = INT_MAX;
            k = 1;
        }
        else if (b == amax)
        {
            if (b == a)
                ++k;
            else
                k = 1;
        }
        else if (b != a && k < kmin)
            kmin = k;
        a = b;
    }
    if (k < kmin)
        kmin = k;
    PutN(kmin);
}
