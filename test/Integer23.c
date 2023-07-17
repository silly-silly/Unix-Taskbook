#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    //PutN(n % 3600 / 60); // 1st solution
    PutN(n / 60 % 60);     // 2nd solution
}
