#include <iostream>
using namespace std;

int pow(int x,int n)
{
    if (n==0)
      return 1;
    if(n%2==0)
       return pow(x*x,n/2);
    else
       return x*pow(x*x,n/2);
    
    
}
int main()
{
    
    
    int a,b;
    cin >>a>>b;
    cout <<pow(a,b);
    return 0;
}