#include "ut1.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
    char s[80];
    GetS(s);
    int k = 0;
    for (char *p = s; *p != 0; ++p)
        if (isalpha(*p)) // if (('A' <= *p && *p <= 'Z') || ('a' <= *p && *p <= 'z'))
            ++k;
    PutN(k);


}
