#include "ut1.h"

int main(int argc, char *argv[])
{
    double b;
    int n;
    GetD(&b);
    GetN(&n);
    int bprocessed = 0;
    // Or
    // bool bprocessed = false;
    for (int i = 0; i < n; ++i)
    {
        double a;
        GetD(&a);
        if (b < a && !bprocessed)
        {
            PutD(b);
            bprocessed = 1;
        }
        PutD(a);
    }
    if (!bprocessed)
        PutD(b);
}
