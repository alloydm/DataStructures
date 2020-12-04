

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
string PostfixToInfix(string post)
{
    stack <string > s;
    for (int i = 0; i < post.length(); i++)
    {
       if (isOperand(post[i]))
       {
           string op(1,post[i]);
           s.push(op);
       }
       else
       {
           string op2 = s.top();
           s.pop();
           string op1 = s.top();
           s.pop();
           s.push("("+op1+post[i]+op2+")");
       }

       
    }
    return s.top();
    
}

int main()
{
    
      string infix, postfix;
    cout << "Enter a POSTFIX Expression :" << endl;
    cin >> postfix;
    cout << "POSTFIX EXPRESSION: " << postfix << endl;
    infix = PostfixToInfix(postfix);
    cout << endl
         << "INFIX EXPRESSION: " << infix;
   
    return 0;
}
