#include "ut1.h"

int main(int argc, char *argv[])
{
    int d, m, k;
    GetN(&d);
    GetN(&m);
    switch (m)
    {
        case 2: 
            k = 28;
            break;
        case 4: case 6: case 9: case 11:
            k = 30;
            break;
        default:
            k = 31;
            break;
    }
    if (d < k)
        ++d;
    else
    {
        d = 1;
        ++m;
        if (m == 13)
            m = 1;
    }
    PutN(d);
    PutN(m);
}
