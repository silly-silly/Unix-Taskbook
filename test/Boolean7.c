#include "ut1.h"

int main(int argc, char *argv[])
{
    int a, b, c;
    GetN(&a);
    GetN(&b);
    GetN(&c);
    // PutB((a < b && b < c) || (c < b && b < a));
    PutB((b - a) * (b - c) < 0);
}
