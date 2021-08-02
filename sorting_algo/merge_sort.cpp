#include <iostream>
using namespace std;


void merge(int a[],int l,int m,int r)
{
    int temp[r+1]; // here r+1 since r is total  no of elements in a-1
    int i,k;
    i=k=l;
    int j=m+1;
    while(i<=m && j<=r)
    {
        if(a[i]<=a[j])
        {

            temp[k]=a[i];
            // cout<<a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            //  cout<<a[j];
            j++;
            k++;
        }
        
    }
    while(i<=m)
    {
        temp[k]=a[i];
        //  cout<<temp[k];
        i++;k++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        j++;k++;
    }
    for(int o=l;o<=r;o++)
    {
        a[o]=temp[o];
    }


}
void mergesort(int a[],int l, int r)
{
    int m;
    if(l<r)
    {m=(l+r)/2;
    mergesort(a,l,m);
    
    mergesort(a,m+1,r);
     
    merge(a,l,m,r);}
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
    mergesort(a,l,r);
    cout<<"\nsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
