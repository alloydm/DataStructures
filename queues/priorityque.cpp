#include <iostream>
#define qs 5
using namespace std;
int ar[qs];
int qfull(int *r)
{
    return *r == (qs-1)? 1:0;
}
int qemp(int *f,int *r)
{
    return *f >*r?1:0;
}
void enq(int *r)
{
    if(qfull(r))
       {
           cout <<"overflow\n";
           return ;
       }
    int i,j,it;
    cout <<"value to insert" <<endl;
    cin >>it;
    *r=*r+1;
    j=*r-1;
    while (j>=-1  && it < ar[j])
    {
        ar[j+1]=ar[j];
       
        j--;
        
        
    }
    ar[j+1]=it;
}
void ascdequ(int *f,int *r)
{
    if(qemp(f,r))
    {
        cout << "queue is empty" <<endl;
        return ;
    }
    cout << ar[*f] <<endl;
    (*f)++;
    if (*f > *r)
    {
        *f = 0;
        *r=-1;
    }

}
void desdequ(int *f,int *r)
{
    if(qemp(f,r))
    {
        cout << "queue is empty" <<endl;
        return ;
    }
    cout << ar[*r] <<endl;
    (*r)--;
    if (*f > *r)
    {
        *f = 0;
        *r=-1;
    }

}
void status(int *f,int *r)
{
    int i;
    if(qemp(f,r))
    {
        cout << "queue is empty " <<endl;
        return ;
    }
    for (i=*f;i<=*r;i++)
    {
        cout << ar[i] <<" ";
    }
    cout <<"\n";
}


int main()
{
    
    int f=0,r=-1,c;
    
    while (1)
    {
         cout <<"options" <<endl;
        cin >>c;
        switch (c)
        {
        case 1:
               enq(&r);
               break;
        case 2:
              ascdequ(&f,&r);
              break;
        case 3:
               desdequ(&f,&r);
               break;
        case 4:
               status(&f,&r);
               break;
        case 5:
               exit(0);
        
        default:
                 cout <<"wrong choice" <<endl;
        }
    }
    
    return 0;
}
