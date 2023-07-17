#include "ut1.h"

int main(int argc, char *argv[])
{
    double x;
    int n;
    GetD(&x);
    GetN(&n);
    double s = 1, p = 1;
    for (int i = 1; i <= n; ++i)
    {
        p *= -x*x/((2*i-1)*(2*i));
        s += p;
    }
    PutD(s);


}
