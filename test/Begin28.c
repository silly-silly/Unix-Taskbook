#include "ut1.h"

// A2, A3, A5, A10, A15

int main(int argc, char *argv[])
{
    double a;
    GetD(&a);
    double b = a * a; // a^2
    PutD(b);
    a = a * b;        // a^3
    PutD(a);
    a = a * b;        // a^5
    PutD(a);
    b = a * a;        // a^10
    PutD(b);
    PutD(a * b);
}
