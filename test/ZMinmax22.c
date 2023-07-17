#include "ut1.h"
#include <float.h>

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double min = DBL_MAX, min1 = DBL_MAX;
    for (int i = 0; i < n; ++i)
    {
        double a;
        GetD(&a);
        if (a < min)
        {
            min1 = min;
            min = a;
        }
        else if (a < min1)
            min1 = a;
    }
    PutD(min);
    PutD(min1);

}
