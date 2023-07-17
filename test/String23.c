#include "ut1.h"

int main(int argc, char *argv[])
{
    char s[80];
    GetS(s);
    char *p = s;
    int k = *p++ - '0';
    while (*p != 0)
        if (*p++ == '+')
            k += *p++ - '0';
        else
            k -= *p++ - '0';
    PutN(k);
}
