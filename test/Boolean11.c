#include "ut1.h"

int main(int argc, char *argv[])
{
    int a, b;
    GetN(&a);
    GetN(&b);
    //PutB(a % 2 == 0 && b % 2 == 0 || a % 2 != 0 && b % 2 != 0) // bad!
    PutB((a + b) % 2 == 0); // good!

}
