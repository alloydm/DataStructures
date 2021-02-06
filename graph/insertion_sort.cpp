#include <iostream>
using namespace std;

void insertionsort(int a[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        j=i-1;
        k=a[i];
        while(j>=0 && (a[j]>k))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
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
    insertionsort(a,n);
    cout<<"\nsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
