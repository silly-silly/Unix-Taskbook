#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double p = 1;
    for (int i = 0; i < n; ++i)
    {
        double a;
        GetD(&a);
        a -= (int)a;
        PutD(a);
        p *= a;
    }
    PutD(p);

}
