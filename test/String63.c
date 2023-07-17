#include "ut1.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
    char s[80];
    int k;
    GetS(s);
    GetN(&k);
    for (char *p = s; *p != 0; ++p)
    {
        if (!isalpha(*p))
            continue;
        char c = isupper(*p) ? 'A' : 'a';
        *p = (*p - c + k) % 26 + c;    
    }
    PutS(s);
}
