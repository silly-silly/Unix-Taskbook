#include "ut1.h"

int main(int argc, char *argv[])
{
    int n, a;
    GetN(&n);
    GetN(&a);
    int kmax = 1, k = 1, p = 0, pmax = 0;
    p = 0;
    for (int i = 1; i < n; ++i)
    {
        int b;
        GetN(&b);
        if (b == a)
            ++k;
        else
        {
            if (k > kmax)
            {
                kmax = k;
                pmax = p;
            }
            k = 1;
            p = i;
        }
        a = b;
    }
    if (k > kmax)
    {
        kmax = k;
        pmax = p;
    }
    PutN(pmax);
    PutN(kmax);
}
