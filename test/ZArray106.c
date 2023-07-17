#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[20]; //!!!!
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    int k = n - 1;
    if (k % 2 == 0)
        --k;
    for (int i = k; i >= 0; i -= 2) // no conditional statement in the loop
    {
        for (int j = n - 1; j >= i; --j)
            a[j + 1] = a[j];
        ++n;
    }
    for (int i = 0; i < n; ++i)
        PutD(a[i]);
}

// void Solve1(void)
// {
//     Task("ZArray106");
//     int n;
//     GetN(&n);
//     double a[20]; //!!!!
//     for (int i = 0; i < n; ++i)
//         GetD(&a[i]);
//     for (int i = n - 1; i >= 0; --i) // with the conditional statement in the loop
//         if (i % 2 != 0)
//         {
//             for (int j = n - 1; j >= i; --j)
//                 a[j + 1] = a[j];
//             ++n;
//         }
//     for (int i = 0; i < n; ++i)
//         PutD(a[i]);
// }
