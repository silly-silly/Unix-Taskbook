#include "ut1.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char s[80];
    GetS(s);
    int k = 0;
    double a = atof(s);
    strcat(s, "1");
    if (a != atof(s))
        k = a == round(a) ? 1 : 2;
    PutN(k);
}
