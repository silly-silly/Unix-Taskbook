#include "ut1.h"
#include <limits.h>


int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    int max = INT_MIN;
    int nmax1, nmax2;
    for (int i = 0; i < n; ++i)
    {
        int a;
        GetN(&a);
        if (a > max)
        {
            max = a;
            nmax1 = nmax2 = i;
        }
        else if (a == max)
            nmax2 = i;
    }
    PutN(nmax1 == nmax2 ? 0 : nmax2 - nmax1 -1);    


}
