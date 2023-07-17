#include "ut1.h"

int main(int argc, char *argv[])
{
    int y;
    GetN(&y);
    PutN((y - 1) / 100 + 1);

}
