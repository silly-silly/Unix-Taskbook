#include "ut1.h"

int main(int argc, char *argv[])
{
    int a, b, c;
    GetN(&a);
    GetN(&b);
    GetN(&c);
    int k1 = a / c;
    int k2 = b / c;
    int n = k1 * k2;  // or simply  n = (a / c) * (b / c);
                      // note: n = (a * b) / (c * c);  is NOT correct!
    PutN(n);
    PutN(a * b - n * c * c);



}
