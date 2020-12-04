#include <iostream>
using namespace std;

double e(double x,double n)
{
    
    static double r;
    if (n==0)
      return r;
    r=1+(x/n)*r;
    return e(x,n-1);
    
    
}
int main()
{
    
    
    double a,b;
    cin >>a>>b;
    cout <<e(a,b);
    return 0;
}