#include <iostream>
using namespace std;

int fib(int n)
{
    
    
    if (n<=1)
      return n;
    return fib(n-2)+fib(n-1);
    
    
}
int main()
{
    
    
    int a;
    cin >>a;
    cout <<fib(a);
    return 0;
}