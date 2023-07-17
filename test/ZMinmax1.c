#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    double a, min, max;
    GetN(&n);
    GetD(&a);
    min = max = a;
    SetWidth(5);
    ShowCmt("a = ");
    ShowD(a);
    ShowCmt("min = ");
    ShowD(min);
    ShowCmt("max = ");
    ShowD(max);
    ShowLine();
    for (int i = 2; i <= n; ++i)
    {
        GetD(&a);
        if (a < min)
            min = a;
        else if (a > max)
            max = a;
        ShowCmt("a = ");
        ShowD(a);
        ShowCmt("min = ");
        ShowD(min);
        ShowCmt("max = ");
        ShowD(max);
        ShowLine();
    }
    PutD(min);
    PutD(max);

}
