#include "ut1.h"

//  a -> b       b -> c       c -> a
// Ctrl+Tab     Alt+Shift+F     Ctrl+S

int main(int argc, char *argv[])
{
    double a, b, c;
    // GetD(&a);
    // GetD(&b);
    // GetD(&c);

    double x = c;
    c = b;
    b = a;
    a = x;

    // double x = a;
    // a = c;
    // c = b;
    // b = x;

    PutD(a);
    PutD(b);
    PutD(c);
}
