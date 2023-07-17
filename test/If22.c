#include "ut1.h"

int main(int argc, char *argv[])
{
    double x, y;
    GetD(&x);
    GetD(&y);
    // if (x > 0 && y > 0)
    //     PutN(1);
    // if (x < 0 && y > 0)
    //     PutN(2);
    // if (x < 0 && y < 0)
    //     PutN(3);
    // if (x > 0 && y < 0)
    //     PutN(4);
    if (x > 0)
        if (y > 0)
            PutN(1);
        else
            PutN(4);
    else        
        if (y > 0)
            PutN(2);
        else
            PutN(3);

}
