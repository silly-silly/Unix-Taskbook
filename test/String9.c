#include "ut1.h"

int main(int argc, char *argv[])
{
    int n;
    GetN(&n);
    char c1, c2;
    GetC(&c1);
    GetC(&c2);
    char s[80];
    for (int i = 0; i < n+2; i += 2)
    {
    	s[i] = c1;
    	s[i+1] = c2;
	}
	s[n+2] = 0;
	PutS(s);

    return 0;
}

