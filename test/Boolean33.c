#include "ut1.h"

int main(int argc, char *argv[])
{
    int a, b, c;
    GetN(&a);
    GetN(&b);
    GetN(&c);
    PutB(a + b > c && a + c > b && b + c > a);

}
