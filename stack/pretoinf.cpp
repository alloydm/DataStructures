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
string preToInfix(string pre)
{
    stack <string> s;
    for (int i = pre.length()-1; i >= 0; i--)
    
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
            s.push("("+op1+pre[i]+op2+")");
        }
        
    }
    return s.top();
    
}
int main()
{
    
    
     string infix, prefix;
    cout << "Enter a PreFIX Expression :" << endl;
    cin >> prefix;
    cout << "PreFIX EXPRESSION: " << prefix << endl;
    infix = preToInfix(prefix);
    cout << endl
         << "INFIX EXPRESSION: " << infix;
   
    return 0;
   
}
