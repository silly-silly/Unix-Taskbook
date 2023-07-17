#include "ut1.h"

int main(int argc, char *argv[])
{
    int m;
    GetN(&m);
    Show("m = ");
    ShowN(m);
    double a[10][10];
    for (int i = 0; i < m; i++)
	    for (int j = 0; j < m; j++)
	    	GetD(&a[i][j]);
    for (int i = 0; i < m; i++)
	    for (int j = 0; j < i; j++)
	    	a[i][j] = 0;
    for (int i = 0; i < m; i++)
	    for (int j = 0; j < m; j++)
	    	PutD(a[i][j]);
    return 0;
}

