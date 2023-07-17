#include "ut1.h"
#include <float.h>

int main(int argc, char *argv[])
{
    double a[6], b[6], c[10];
    for (int i = 0; i < 5; ++i)
        GetD(&a[i]);
    for (int i = 0; i < 5; ++i)
        GetD(&b[i]);
    a[5] = DBL_MAX;    // barrier elements!
    b[5] = DBL_MAX;    
    int ka = 0, kb = 0;
    for (int i = 0; i < 10; ++i)
        if (a[ka] < b[kb])
            c[i] = a[ka++];
        else    
            c[i] = b[kb++];
    for (int i = 0; i < 10; ++i)
        PutD(c[i]);
}
