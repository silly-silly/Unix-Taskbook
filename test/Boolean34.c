#include "ut1.h"

int main(int argc, char *argv[])
{
    int x, y;
    GetN(&x);
    GetN(&y);
    PutB((x+y) % 2 != 0);
//    PutB((x+y) % 2);  // unclear...

}
