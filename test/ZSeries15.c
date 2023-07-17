#include "ut1.h"

int main(int argc, char *argv[])
{
    int k, a, res = -1, i = -1;
    GetN(&k);
    GetN(&a);
    while (a != 0)
    {
        ++i;
        if (a > k)
        {
            res = i;
            break;
        }
        GetN(&a); //!!!
    }
    PutN(res);

}
