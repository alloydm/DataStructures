#include <iostream>
using namespace std;

int maxi(int a[],int n)
{
    int k=a[0];
    for (int i = 1; i < n; i++)
    {
        if(k < a[i])
          k=a[i];
    }
    return k;
    
}
void countsort(int a[],int n,int ra,int i)
{
    int out[n],count[ra];
    for (int j = 0; j < ra; j++)
    {
        count[j]=0;
    }
    for (int j = 0; j <n; j++)
    {
       ++count[(a[j]/i)%10];
    }
    for (int j = 1; j <ra; j++)
    {
       count[j]=count[j]+count[j-1];
    }
    for (int j = n-1; j >=0; j--)
    {
       out[--count[(a[j]/i)%10]]=a[j];
    }
    for (int j = 0; j <n; j++)
    {
       a[j]=out[j];
    }


    
    
}
void radixsort(int a[],int n,int ra)
{
    int ma=maxi(a,n);
    for (int i = 1; ma/i >0; i=i*10)
    {
        countsort(a,n,ra,i);
    }
    
}
int main()
{
    
      int n,ra;
    cin>>n;
    int a[n];
    cout<<"put range"<<endl;
    cin>>ra;
   
    for(int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    cout<<"unsorted array"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
    radixsort(a,n,ra);
    cout<<"\nsorted array"<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
    return 0;
}

