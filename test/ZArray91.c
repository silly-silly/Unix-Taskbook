#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    int k, l;
    GetN(&k);
    GetN(&l);
    int d = l - k + 1;
    for (int i = l + 1; i < n; ++i)
        a[i - d] = a[i];
    n -= d;        
    PutN(n);    
    for (int i = 0; i < n; ++i)
         PutD(a[i]);

}
