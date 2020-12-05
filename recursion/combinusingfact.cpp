//using factorial for combination
#include <iostream>
using namespace std;
int fun(int );

int com(int a,int r)
{
    int b,c,d;
    b=fun(a);
    c=fun(a-r);
    d=fun(r);
    return b/(c*d);
}
int fun(int n)
{
    if (n==0)
      return 1;
    return fun(n-1)*n;
    
}
int main()
{
    
    
    int a,r;
    cin >>a>>r;
    cout <<com(a,r);
    return 0;
}