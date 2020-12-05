#include <iostream>
using namespace std;

int fib(int n)
{
    static int s=0,a=0;
    int c;
    
    if (n<=1)
      return n;
    c=fib(n-1);
    s=a+c;
    a=c;

    cout <<a<<" ";
    return s;
    
    
}
int main()
{
    
    
    int a;
  
    cin >>a;
 
    cout <<fib(a);
    return 0;
}