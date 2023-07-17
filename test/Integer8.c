#include "ut1.h"

int main(int argc, char *argv[])
{
    int n, a, b;
    GetN(&n);
    b = n % 10;
    a = n / 10;
    PutN(b * 10 + a);

}
