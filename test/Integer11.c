#include "ut1.h"

int main(int argc, char *argv[])
{
    int n, a, b, c;
    GetN(&n);
    c = n % 10;
    n = n / 10;
    b = n % 10;
    a = n / 10;
    PutN(a + b + c);
    PutN(a * b * c);

}
