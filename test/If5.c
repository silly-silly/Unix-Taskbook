#include "ut1.h"

int main(int argc, char *argv[])
{
    int a , b , c ;
    int p , n ;
    GetN(&a);
    GetN(&b);
    GetN(&c);
    if (a>0&&b>0&&c>0)
    {
        PutN(p=3);
        PutN(n=0);
    }
    if (a>0&&b<0&&c>0)
    {
        PutN(p=2);
        PutN(n=1);
    }
    
    if (a>0&&b>0&&c<0)
    {
        PutN(p=2);
        PutN(n=1);
    }
    if (a>0&&b<0&&c<0)
    {
        PutN(p=1);
        PutN(n=2);
        Show(p);
    }if (a<0&&b>0&&c>0)
    {
        PutN(p=2);
        PutN(n=1);
    }if (a<0&&b<0&&c>0)
    {
        PutN(p=1);
        PutN(n=2);
    }if (a<0&&b>0&&c<0)
    {
        PutN(p=1);
        PutN(n=2);
    }
    if (a<0&&b<0&&c<0)
    {
        PutN(p=0);
        PutN(n=3);
    }
    if (a==0&&b>0&&c>0)
    {
        PutN(p=2);
        PutN(n=0);
    }
    if (a==0&&b<0&&c>0)
    {
        PutN(p=1);
        PutN(n=1);
    }
    if (a==0&&b>0&&c<0)
    {
        PutN(p=1);
        PutN(n=1);
    }
    if (a==0&&b<0&&c<0)
    {
        PutN(p=0);
        PutN(n=2);
    }
    if (a>0&&b==0&&c>0)
    {
        PutN(p=2);
        PutN(n=0);
    }
    if (a<0&&b==0&&c>0)
    {
        PutN(p=1); 
        PutN(n=1);
    }
    if (a>0&&b==0&&c<0)
    {
        PutN(p=1);
        PutN(n=1);
    }
    if (a<0&&b==0&&c<0)
    {
        PutN(p=0);
        PutN(n=2);
    }
    if (a>0&&b>0&&c==0)
    {
        PutN(p=2);
        PutN(n=0);
    }
    if (a<0&&b>0&&c==0)
    {
        PutN(p=1);
        PutN(n=1);
    }
    if (a>0&&b<0&&c==0)
    {
        PutN(p=1);
        PutN(n=1);
    }
    if (a<0&&b<0&&c==0)
    {
        PutN(p=0);
        PutN(n=2);
    }
    if (a==0&&b==0&&c>0)
    {
        PutN(p=1);
        PutN(n=0);
    }
    if (a==0&&b==0&&c<0)
    {
        PutN(p=0);
        PutN(n=1);
    }
    
    if (a>0&&b==0&&c==0)
    {
        PutN(p=1);
        PutN(n=0);
    }
    if (a<0&&b==0&&c==0)
    {
        PutN(p=0);
        PutN(n=1);
    }
    if (a==0&&b>0&&c==0)
    {
        PutN(p=1);
        PutN(n=0);
    }
    if (a==0&&b<0&&c==0)
    {
        PutN(p=0);
        PutN(n=1);
    
    }
    if (a==0&&b==0&&c==0)
    {
        PutN(p=0);
        PutN(n=0);
    }
    

}
