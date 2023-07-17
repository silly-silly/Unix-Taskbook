#include "ut1.h"
#include <math.h>

int main(int argc, char *argv[])
{
    double x;
    GetD(&x);
    if (x < 0)
        PutN(0);
    else if ((int)x % 2 == 0)
        PutN(1);
    else
        PutN(-1);
    ShowN(-5.4);
}
