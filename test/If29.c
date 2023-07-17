#include "ut1.h"

int main(int argc, char *argv[])
{
    int x;
    GetN(&x);
    // if (x == 0)   // variant 1
    //     PutS("zero number");
    // if (x < 0 && x % 2 != 0)
    //     PutS("negative odd number");
    // if (x < 0 && x % 2 == 0)
    //     PutS("negative even number");
    // if (x > 0 && x % 2 != 0)
    //     PutS("positive odd number");
    // if (x > 0 && x % 2 == 0)
    //     PutS("positive even number");

    // if (x == 0)     // variant 2
    //     PutS("zero number");
    // else if (x < 0)
    // {
    //     if (x % 2 != 0)
    //         PutS("negative odd number");
    //     else    
    //         PutS("negative even number");
    // }            
    // else if (x % 2 != 0)       
    //     PutS("positive odd number");
    // else
    //     PutS("positive even number");

    char s[30];    // variant 3
    if (x == 0)
        strcpy(s, "zero");
    else
    {
        if (x < 0)
            strcpy(s, "negative");
        else    
            strcpy(s, "positive");
        if (x % 2 != 0)    
            strcat(s, " odd");
        else    
            strcat(s, " even");
    }
    strcat(s, " number");
    PutS(s);
}
