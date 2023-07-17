#include "ut1.h"

int main(int argc, char *argv[])
{
    double a;
    GetD(&a);
    //PutD(a*a*a*a*a*a*a*a);
    a = a * a; // a * a = a^2
    PutD(a);
    a = a * a; // a^2 * a^2 = a^4
    PutD(a);
    // PutD(a * a); // a^4 * a^4 = a^8
    //a^16

}
