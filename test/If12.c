#include "ut1.h"

int main(int argc, char *argv[])
{
    double a, b, c;
    GetD(&a);
    GetD(&b);
    GetD(&c);
    // if (a < b && a < c)
    //     PutD(a);
    // if (b < a && b < c)
    //     PutD(b);
    // if (c < b && c < a)
    //     PutD(c);

    if (a < b && a < c)
        PutD(a);
    else if (b < c)
        PutD(b);
    else
        PutD(c);


        
}
