#include "ut1.h"

int main(int argc, char *argv[])
{
    int m, n;
    int a[10][10];
    GetN(&m);
    GetN(&n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            GetN(&a[i][j]);
    int res = -1;
    for (int j = n - 1; j >= 0; --j)
    {
        int cnt = 0;
        for (int i = 0; i < m; ++i)
            if (a[i][j] > 0)
                ++cnt;
            else if (a[i][j] < 0)
                --cnt;
        if (cnt == 0)
        {
            res = j;
            break;
        }
    }
    PutN(res);
}
