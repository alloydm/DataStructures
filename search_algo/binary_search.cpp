#include <iostream>
using namespace std;

void binarysearch(int *a,int n,int k)
{
    int l,h,mid,t=0;
    l=0;
    h=k-1;
    cout <<h;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==n)
        {
            cout <<"the value is found at "<<mid+1<<endl;
            t=1;
            break;

        }
        else if(a[mid]<n)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
        
        
    }
    if(t==0)
    {
        cout<<" Element not found"<<endl;
    }

}
int main()
{
    
     int ar[10],n,k;
     k=sizeof(ar)/sizeof(*ar);
     cout <<k<<endl;
    for(int i=0;i<=9;i++)
    {
        cin >>ar[i];
    }
    cin >>n;
  binarysearch(ar,n,k);
  
    return 0;
}
