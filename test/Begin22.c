#include "ut1.h"

// F5  Shift+<- -> 
int main(int argc, char *argv[])
{
    double a, b;
    GetD(&a);
    GetD(&b);

    // double x = a;
    // a = b;
    // b = x;

    a += b;
    b = a - b;
    a -= b;

    PutD(a);
    PutD(b);

}
