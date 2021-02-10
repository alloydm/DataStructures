#include <iostream>
using namespace std;

void shellsort(int a[],int n)
{
    int i,j,k,t;
    for(i=n/2;i>0;i=i/2)
    {
        for(j=0,k=(j+i);k<n;j++,k++)
        {
            if(a[j]>a[k])
            {
              t=a[j];
              a[j]=a[k];
              a[k]=t;  
            }
        }
        for(j=n-1,k=(j-i);k>=0;j--,k--)
        {
            if(a[j]<a[k])
            {
              t=a[j];
              a[j]=a[k];
              a[k]=t;  
            }
        }
    }
}
int main()
{
    
     
    int n;
    cin>>n;
    int a[n];
  
   
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"unsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    shellsort(a,n);
    cout<<"\nsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
