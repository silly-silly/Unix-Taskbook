#include "ut1.h"
#include <string.h>

int main(int argc, char *argv[])
{
    char s[80];
    GetS(s);
    char **w = malloc(10 * sizeof(char *));
    strcat(s, " ");
    int n = 0;
    while (*s != 0) // long but standard algorithm
    {
        char *p = strchr(s, ' ');
        *p++ = 0;
        w[n] = malloc(80);
        strcpy(w[n], s);
        ShowS(w[n]);
        ++n;
        while (*p == ' ')
            ++p;
        strcpy(s, p);
    }

    for (int k = 1; k < n; ++k) // sorting
        for (int i = 0; i < n - k; ++i)
            if (strcmp(w[i], w[i + 1]) > 0)
            {
                char *t = w[i];
                w[i] = w[i + 1];
                w[i + 1] = t;
            }

    strcpy(s, w[0]);
    for (int i = 1; i < n; ++i)
    {
        strcat(s, " ");
        strcat(s, w[i]);
    }
    PutS(s);

    for (int i = 0; i < n; ++i)
        free(w[i]);
    free(w);
}
