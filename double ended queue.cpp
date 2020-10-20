#include <iostream>
using namespace std;
#define q1 5
int qfull(int *r)
{
  return *r == (q1-1)? 1:0;
}
int qemp(int *f,int *r)
{
  return *f > *r ? 1 :0 ;
}
int qar[q1],f=0,r=-1;
void delfront(int qar[] , int *f ,int *r)
{
  if(qemp(f,r))
     {
      cout <<"queue empty" <<endl;
       return;
     }
  cout <<qar[*f] <<endl;
  ++(*f);
  if(*f > *r)
  {
    *f = 0;
    *r =-1;
  }
}
void delrear(int qar[],int *f ,int *r)
{
  if(qemp(f, r))
  {
    cout <<"queue empty" <<endl;
    return;
  }
  cout <<qar[(*r)--] <<endl;
  if(*f > *r)
  {
    *f = 0;
    *r = -1;
  }
}
void insrear(int qar[],int *r)
{
  int it;
  if(qfull(r))
  {
     cout <<"queue full" <<endl;
    return ;
  }
  cout <<"enter option" <<endl;
  cin >> it;
  qar[++(*r)]=it;
}
void insfront(int qar[],int *f , int *r)
{
  int it;
  if (*f == 0 && *r == -1)
  {
    cout <<"enter option" <<endl;
    cin >> it;
    qar[++(*r)]=it;
  }
  else if(*f >0)
  {
    cout <<"enter option" <<endl;
    cin >> it;
    qar[--(*f)]=it;
  }
  else{
    cout << "insert at front not possible" <<endl;
  }
}
void status(int qar[] , int *f,int *r)
{
  int i;
  if(qemp(f, r))
  {
    cout <<"queue empty" <<endl;
    return ;
  }
  for(i=*f;i<=*r;i++)
  {
    cout << qar[i] <<endl;
  }
}
int main()
{
  int ch;
  while(1)
  { cout <<"enter option" <<endl;
    cin >> ch;
    switch(ch)
    {
      case 1:
             insfront(qar, &f,&r);
             break;
      case 2:
             insrear(qar, &r);
             break;
      case 3:
             delfront(qar,&f,&r);
             break;
      case 4:
             delrear(qar,&f, &r);
             break;
      case 5:
             status(qar,&f,&r);
             break;
      default:
              exit(0);
    }
  }

    }
  

