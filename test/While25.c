#include "ut1.h"

int main(int argc, char *argv[])
{
    int n, a = 1, b = 1;
    GetN(&n);
    while (b <= n)
    {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    PutN(b);
}
