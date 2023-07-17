#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    double a[10];
    for (int i = 0; i < n; ++i)
        GetD(&a[i]);
    int k;
    GetN(&k);
    for (int j = 0; j < k; ++j)
    {
        double b;
        b = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            a[i + 1] = a[i];
        a[0] = b;
    }
    for (int i = 0; i < n; ++i)
        PutD(a[i]);
}

// void Solve1(void)
// {
//     Task("ZArray85");
//     int n;
//     GetN(&n);
//     double a[10];
//     for (int i = 0; i < n; ++i)
//         GetD(&a[i]);
//     int k;
//     GetN(&k);
//     double b[4];
//     for (int i = n - k; i < n; ++i) // (n - k) .. (n - 1) - k last elements
//         b[i - (n - k)] = a[i];
//     for (int i = n - k - 1; i >= 0; --i)
//         a[i + k] = a[i];
//     for (int i = 0; i < k; ++i)
//         a[i] = b[i];
//     for (int i = 0; i < n; ++i)
//         PutD(a[i]);
// }
