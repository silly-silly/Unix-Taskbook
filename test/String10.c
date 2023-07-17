#include "ut1.h"
#include <string.h>

void Swap(char *c1, char *c2)
{
    char x = *c1;
    *c1 = *c2;
    *c2 = x;
}

int main(int argc, char *argv[])
{
    char s[80], s1[80];
    GetS(s);
    int n = strlen(s);
    char *p = s + (n - 1);
    char *p1 = s1;
    for (int i = 0; i < n; ++i)
        *p1++ = *p--;
    *p1 = 0;
    PutS(s1);
}
