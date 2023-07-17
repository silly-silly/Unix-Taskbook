#include "ut1.h"
#include <string.h>

int main(int argc, char *argv[])
{
    int n;
    char s[80];
    GetN(&n);
    GetS(s);
    int len = strlen(s);
    if (n < len)
        strcpy(s, s + (len - n));
    else
    {
        memmove(s + (n - len), s, len + 1);
        memset(s, '.', n - len);
    }    
    PutS(s);
}
