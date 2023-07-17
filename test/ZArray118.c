#include "ut1.h"

int main(int argc, char *argv[])
{// more efficient solution
    int n;
    GetN(&n);
    int a[20]; // a[20] !!
    for (int i = 0; i < n; ++i)
        GetN(&a[i]);
    a[n++] = 0;
    for (int i = n - 2; i > 0; --i)
        if (a[i] != a[i - 1])
        {
            for (int j = n - 1; j >= i; --j)
                a[j + 1] = a[j];
            a[i] = 0;
            ++n;
        }
    for (int i = 0; i < n; ++i)
        PutN(a[i]);
}

// void Solve1(void)
// {
//     Task("ZArray118");
//     int n;
//     GetN(&n);
//     int a[20], b[10], c[10]; // a[20] !!
//     for (int i = 0; i < n; ++i)
//         GetN(&a[i]);
//     int k = 1;
//     b[0] = 1;
//     c[0] = a[0];
//     for (int i = 1; i < n; ++i)
//         if (a[i] == a[i - 1])
//             ++b[k - 1];
//         else
//         {
//             ++k;
//             b[k - 1] = 1;
//             c[k - 1] = a[i];
//         }
//     n = 0;
//     for (int i = 0; i < k; ++i)
//     {
//         for (int j = 0; j < b[i]; ++j)
//             a[n++] = c[i];
//         a[n++] = 0;
//     }
//     for (int i = 0; i < n; ++i)
//         PutN(a[i]);
// }
