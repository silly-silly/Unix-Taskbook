#include "ut1.h"
#include <string.h>

int main(int argc, char *argv[])
{
    char s[80];
    GetS(s);
    int n = 1;
    for (char *p = s + 1; *p != 0; ++p)
        if (*p != ' ' && *(p - 1) == ' ')
            ++n;
    PutN(n);
}

// void Solve2()
// {
//     Task("String41");
//     char s[80];
//     GetS(s);
//     int n = 1;
//     int len = strlen(s);
//     for (int i = 1; i < len; ++i)
//         if (s[i] != ' ' && s[i - 1] == ' ')
//             ++n;
//     PutN(n);
// }

// void Solve1()
// {
//     Task("String41");
//     char s[80];
//     GetS(s);
//     strcat(s, " ");
//     int n = 0;
//     while (*s != 0)
//     {
//         char *p = strchr(s, ' ');
//         ++n;
//         // how to obtain the current word
//         char w[80];
//         *p++ = 0;
//         strcpy(w, s);
//         ShowS(w);
//         //
//         while (*p == ' ')
//             ++p;
//         strcpy(s, p);
//     }
//     PutN(n);
// }
