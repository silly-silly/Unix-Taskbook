#include "ut1.h"
#include <string.h>

int main(int argc, char *argv[])
{
    char s[80]; //!!
    GetS(s);    // without & !!
    PutN(s[0]);
    PutN(s[strlen(s) - 1]);
}
