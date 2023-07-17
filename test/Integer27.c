#include "ut1.h"

int main(int argc, char *argv[])
{
    int k;
    GetN(&k);
    PutN((k + 4) % 7 + 1);

// K  1  2  3  4  5  6  7  8  9 10 11 ...
// D  6  7  1  2  3  4  5  6  7  1  2 ...
//formula?  D = (k + x) % 7 + 1  - we obtain the correct sequence of numbers 1..7
//          Select x such that the formula will be correct for k == 1:
//          (1 + x) % 7 should be 5  =>  x = 4

}
