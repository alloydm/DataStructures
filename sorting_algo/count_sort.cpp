#include <iostream>
using namespace std;

void countsort(int a[],int n,int ra)
{
    int out[n],count[ra];
    for (int i = 0; i < ra; i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        ++count[a[i]];
    }
    for(int i=1;i<ra;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=0;i<n;i++)
    {
        out[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=out[i];
    }
    
}

int main()
{
    
    
    int n,ra;
    cin>>n;
    int a[n];
    cout<<"put range"<<endl;
    cin>>ra;
   
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"unsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    countsort(a,n,ra);
    cout<<"\nsorted array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
