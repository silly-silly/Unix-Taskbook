#include "ut1.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
    char s[80];
    GetS(s);
    for (char *p = s; *p != 0; ++p)
        if (islower(*p)) // if ('a' <= *p && *p <= 'z')
            *p = toupper(*p);  // *p -= 32;
    PutS(s);

}
