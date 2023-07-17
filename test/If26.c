#include "ut1.h"

int main(int argc, char *argv[])
{
    double x, y;
    GetD(&x);
    // if (x <= 0)
    //     y = -x;
    // if (0 < x && x < 2)
    //     y = x * x;
    // if (x >= 2)
    //     y = 4;
    if (x <= 0)
        y = -x;
    else if (x < 2)
        y = x * x;
    else
        y = 4;
    PutD(y);
}
