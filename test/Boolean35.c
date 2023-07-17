#include "ut1.h"

int main(int argc, char *argv[])
{
    int x1, y1, x2, y2;
    GetN(&x1);
    GetN(&y1);
    GetN(&x2);
    GetN(&y2);
    PutB((x1 + y1 + x2 + y2) % 2 == 0);
}
