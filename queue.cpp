#include <iostream>
using namespace std;
class Queue
{
    int f,r,arr[5];
    public:
         Queue()
         {
             f=r=-1;
             for (int i=0;i<5;i++)
             {
                 arr[i]=0;
             }
         }
         bool isEmpty()
         {
            if(f == -1 && r==-1)
               return true;
            else
               return false;
         }
         bool isFull()
         {
             if (r == 4)
               return true;
             else
               return false;
         }
         void enqu(int val)
         {
             if(isFull())
                {
                    cout << "it is full" <<endl;
                
                }
            else if(isEmpty())
            {
                r=f=0;
            }
            else
            {
                r++;
            }
            arr[r] =val;
         }
         int deque()
         {
             int x;
             if(isEmpty())
             {
                 cout <<"it is empty" <<endl;
                 return 0;
             }
             else if(f == r)
             {
                 x =arr[r];
                 arr[f] =0;
                 r =f =-1;
                 return x;
             }
             else
             {
                  x =arr[f];
                 arr[f] =0;
                 f++;
                 return x;
             }
         }
         int count()
         {
             return r-f+1;
         }
};


int main(void){
    Queue q1;
    int op=0,val;
    do 
    {
        cout << "endter" <<endl;
        cin >> op;
        switch (op)
        {
            case 1:
                    cin >> val;
                    q1.enqu(val);
                    break;
            case 2: 
                    cout << q1.deque() <<endl;
                    break;
            case 3:
                   cout << q1.count() <<endl;
                   break;
            default:
                    break;
        }
    }while(op !=0);
    return 0;
    
    
}


