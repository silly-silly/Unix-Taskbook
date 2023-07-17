#include "ut1.h"
#include <string.h>

int main(int argc, char *argv[])
{
    char s[80], s0[80];
    GetS(s);
    GetS(s0);
    int len0 = strlen(s0);
    char *p0 = 0;
    for (char *p = s + strlen(s) - len0; p >= s; --p) 
        if (memcmp(p, s0, len0) == 0)
        {
            p0 = p;
            break;
        }    
    if (p0 != 0)    
        strcpy(p0, p0 + len0);
    PutS(s);
}
