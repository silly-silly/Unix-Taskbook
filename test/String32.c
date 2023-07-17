#include "ut1.h"
#include <string.h>

int main(int argc, char *argv[])
{
    char s[80], s0[80];
    GetS(s);
    GetS(s0);
    int k = 0;
    char *p = strstr(s, s0);
    while (p != 0)
    {
        ++k;
        p = strstr(p + 1, s0);
    }
    PutN(k);

}
