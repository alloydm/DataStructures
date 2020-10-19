#include <iostream>
#include <string>
using namespace std;
class stack
{
private:
    int top;
    int arr[5];
public:
    stack ()
    {
        top=-1;
        for (int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    void push(int);
    int pop(void);
    bool isempty(void);
    bool isfull(void);
    int peek(int);
    int count(void);
    void change(int,int);
    void display(void);
};

void stack :: push(int val)
{
    if(isfull())
    {
        cout << "stack overflow" <<endl;
    }
    else
    {
        top++;
        arr[top] = val;
        cout <<"push success" <<endl;
    }

}
int stack :: pop()
{
    if(isempty())
    {
        cout << "stack undeflow" <<endl;
        return 0;
        
    }
    else
    {
        int vals = arr[top];
        arr[top]=0;

        top--;
        return vals;
    }

}
bool stack ::isempty()
{
    if (top ==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool stack ::isfull()
{
    if (top == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int stack ::peek(int index)
{
     if(isempty())
    {
        cout << "stack undeflow" <<endl;
        return 0;
    }
    else
    {
      return (arr[index]);
    }


}
int stack ::count()
{
    return (top+1);
}
void stack ::change(int pos ,int val)
{
     if(isempty())
    {
        cout << "stack undeflow" <<endl;
        
    }
    else
    {
     cout  << arr[pos];
      arr[pos] = val;
      cout <<"change success" <<endl;
      cout  << arr[pos];
    }

}
void stack ::display()
{
    for (int i=4;i >=0 ;i--)
    {
        cout << arr[i] <<endl;
    }
}



int main()
{
    int option , position , value;
    stack s1;
    do
    {
        cin >>option ;
        switch (option)
        {
        case 1:
             cout << "enter the value to push";
             cin >> value;
             s1.push(value);
             break;
        case 2:
           cout <<"the popped val is" <<endl;
           cout << s1.pop();
           break;
         case 3:
           if(s1.isempty())
           {
               cout << "stack is empty" <<endl;
           }
           else
           {
               cout << "not empty" <<endl;
           }
           
            break;
         case 4:
              if(s1.isfull())
           {
               cout << "stack is full" <<endl;
           }
           else
           {
               cout << "not full" <<endl;
           }
           
            break;
         case 5:
          
            cout << "enter the index" <<endl;
            cin >> position;
           cout << s1.peek(position) ;
             
           
            break;
         case 6:
               cout << s1.count();
           
            break;
         case 7:
             cout << "pos n val to change" <<endl;
             cin >> position >> value;
             s1.change(position,value);

           
            break;
         case 8:
             cout << "the display is" <<endl;
             s1.display();
           
            break;
        
        default:
            break;
        }
    } while (option !=0);
    
    
    
    
    return 0;
}

