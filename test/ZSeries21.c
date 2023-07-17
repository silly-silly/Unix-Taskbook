#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    double a, b;
    int res = 1;
    // Or
    // bool res = true;
    GetN(&n);
    GetD(&a);
    for (int i = 1; i < n; ++i)
    {
        GetD(&b);
        if (a >= b)
        {
            res = 0;
            break;
        }
        a = b;
    }
    PutB(res);

}
