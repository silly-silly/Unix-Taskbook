#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    int a[10], b[10], c[10];
    for (int i = 0; i < n; ++i)
        GetN(&a[i]);
    int k = 1;
    b[0] = 1;
    c[0] = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i-1])
            ++b[k-1];
        else
        {
            ++k;
            b[k - 1] = 1;
            c[k - 1] = a[i];
        }
    for (int i = 0; i < k; ++i)        
        PutN(b[i]);
    for (int i = 0; i < k; ++i)        
        PutN(c[i]);

}
