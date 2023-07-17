#include "ut1.h"

int main(int argc, char *argv[])
{
    double a, b;
    GetD(&a);
    GetD(&b);
    // if (a > b)
    //     PutD(a);
    // else
    //     PutD(b);

    PutD(a > b ? a : b);
}
