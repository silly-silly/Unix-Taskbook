#include "ut1.h"
#include <float.h>

int main(int argc, char *argv[])
{
    double b;
    GetD(&b);
    double min = DBL_MAX; 
    int nmin = -1;
    for (int i = 0; i < 10; ++i)
    {
        double a;
        GetD(&a);
        if (a > b && a < min)
        {
            min = a;
            nmin = i;
        }
    }
    if (min == DBL_MAX)
        min = -1;
    PutD(min);
    PutN(nmin);
}
