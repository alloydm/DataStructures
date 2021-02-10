#include <iostream>
using namespace std;


int partition(int a[],int l,int r)
{
    int pivot=a[r],te;
    int pindex=l;
    for(int i=l;i<=r-1;i++)
    {
        if(a[i]<=pivot)
        {
            int t;
            t=a[i];
            a[i]=a[pindex];
            a[pindex]=t;
            pindex++;
        }
    }
    te=a[r];
    a[r]=a[pindex];
    a[pindex]=te;
    cout <<a[pindex] <<endl;
  

    return pindex;

}
void quicksort(int a[],int l,int r )
{
    int p;
    if (l<r)
    {
        p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
    
   
    }
int main()
{
    
    int n;
    cin>>n;
    int a[n];
    int l=0,r=n-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"unsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    quicksort(a,l,r);
    cout<<"\nsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
