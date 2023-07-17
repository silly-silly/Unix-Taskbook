#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    for (int i = 0; i < n; ++i)
        PutC('A' + i);  // PutC((char)((int)'A' + i));

}
