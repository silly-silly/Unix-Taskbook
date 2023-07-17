#include "ut1.h"

int main(int argc, char *argv[])
{
    char c;
    int n, k;
    GetC(&c);
    GetN(&n);
    switch (c)
    {
        case 'N':
            k = 4;
            break;
        case 'W':
            k = 5;
            break;
        case 'S':
            k = 6;
            break;
        case 'E':
            k = 7;
            break;
    }
    k += n;
    switch (k % 4)
    {
        case 0:
            c = 'N';
            break;
        case 1:
            c = 'W';
            break;
        case 2:
            c = 'S';
            break;
        case 3:
            c = 'E';
            break;
    }
    PutC(c);


}
