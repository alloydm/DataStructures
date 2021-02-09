#include <iostream>
using namespace std;

void linearsearch(int a[],int n)
{
    int temp=-1;
    for(int i=0;i<5;i++)
    {
        if(a[i] == n)
        {
            cout << "element is found at "<<i+1<<endl;
            temp=0;
            break;
        }
    }
    if(temp!=0)
    {
        cout<<" Element not found"<<endl;
    }
}
int main()
{
    int ar[5],n;
    for(int i=0;i<5;i++)
    {
        cin >>ar[i];
    }
    cin >>n;
    linearsearch(ar,n);
    return 0;
}
