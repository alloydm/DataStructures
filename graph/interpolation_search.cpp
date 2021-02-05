#include <iostream>
using namespace std;

int interpol(int a[],int n)
{
    int pos,low,high;
    low=0;
    high=sizeof(a)-1;
    while(low<=high)
    {
        pos=low+((high-low)/(a[high]-a[low]))*(n-a[low]);
        if(a[pos]==n)
           return pos;
        else if(a[pos]<n)
            low=pos+1;
        else
           high = pos-1;      
            
    }
    return -1;
}
int main()
{
      int ar[10],n;

    for(int i=0;i<=9;i++)
    {
        cin >>ar[i];
    }
    cin >>n;
    int val=interpol(ar,n);
    if(val!=-1)
       cout << "the val is at pos "<<val+1<<endl;
    else
      cout<<" element cannot be found"<<endl;
    
    
    
    
    return 0;
}
