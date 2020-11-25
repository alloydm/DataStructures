#include <iostream>
#include <stack>
 
using namespace std;
 
bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}

string pretopost(string pre)
{
    stack < string > s;
    for (int i = pre.length()-1; i >=0; i--)
    {
        if(isOperand(pre[i]))
        {
            string op(1,pre[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(op1+op2+pre[i]);
        }
        

    }
    return s.top();
}

  int main()
{
    
    
     string post, pre;
    cout << "Enter a preFIX Expression :" << endl;
    cin >> pre;
    cout << "PreFIX EXPRESSION: " << post<< endl;
    post = pretopost(pre);
    cout << endl
         << "Postfix EXPRESSION: " << post;
   
    return 0;
   
}
 
