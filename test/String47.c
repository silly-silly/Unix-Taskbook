#include "ut1.h"
#include <string.h>


int main(int argc, char *argv[])
{
    char s[80];
    GetS(s);
    char w[10][80];
    strcat(s, " ");
    int n = 0;
    while (*s != 0)  // long but standard algorithm
    {
        char *p = strchr(s, ' ');
        *p++ = 0;
        strcpy(w[n], s);
        ShowS(w[n]);
        ++n;
        while (*p == ' ')
            ++p;
        strcpy(s, p);
    }
    strcpy(s, w[0]);
    for (int i = 1; i < n; ++i)
    {
        strcat(s, ".");
        strcat(s, w[i]);
    }
    PutS(s);
}


// int main(int argc, char *argv[])
// {
//     char s[80];
//     GetS(s);
//     char *pw;
//     for (char *p = s + strlen(s) - 1; p != s; --p)
//         if (*p != ' ' && *(p-1) == ' ')
//             pw = p;
//         else if (*p == ' ' && *(p - 1) != ' ')
//         {
//             *p = '.';
//             strcpy(p + 1, pw);
//         }
//     PutS(s);
// }
