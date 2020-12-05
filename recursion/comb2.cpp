//using pascal triangle
//using factorial for combination
#include <iostream>
using namespace std;


int com(int a,int r)
{
    if (r==0 || a==r)
      return 1;
    return com(a-1,r-1)+com(a-1,r); // example 4c2 = 3c2+3c1 n so on
    
}

int main()
{
    
    
    int a,r;
    cin >>a>>r;
    cout <<com(a,r);
    return 0;
}