#include "ut1.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x1, y1, x2, y2;
    GetN(&x1);
    GetN(&y1);
    GetN(&x2);
    GetN(&y2);
    PutB(abs(x2 - x1) * abs(y2 - y1) == 2);
}
