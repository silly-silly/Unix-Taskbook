#include "ut1.h"
#include <string.h>

// int main(int argc, char *argv[])
// {
//     int n1, n2;
//     char s1[80], s2[80], s[80];
//     GetN(&n1);
//     GetN(&n2);
//     GetS(s1);
//     GetS(s2);
//     s1[n1] = 0;
//     memcpy(s, s1, n1);
//     memcpy(s + n1, s2 + strlen(s2) - n2, n2);
//     s[n1 + n2] = 0;
//     PutS(s);
// }

int main(int argc, char *argv[])
{
    int n1, n2;
    char s1[80], s2[80];
    GetN(&n1);
    GetN(&n2);
    GetS(s1);
    GetS(s2);
    s1[n1] = 0;
    PutS(strcat(s1, s2 + strlen(s2) - n2));
}
