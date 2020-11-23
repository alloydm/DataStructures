#include <iostream>
#include<stack>
using namespace std;
bool isoperator(char c)
{
 if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
 {
 return true;
 }
 else
 {
 return false;
 }
}
 
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
 
string InfixToPostfix(stack <char> s,string infix)
{
    string post;
    for (int i=0;i<infix.length();i++)
    {
        if ((infix[i] >= 'a' && infix[i] <='z') || (infix[i]>='A' && infix[i] <='Z'))
        {
            post+=infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while ((s.top()!='(') && (!s.empty()))
            {
                post+=s.top();
                s.pop();
            }
            if(s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isoperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (prec(infix[i]) > prec(s.top()))
                {
                    s.push(infix[i]);
                }
                else if((prec(infix[i]) == prec(s.top())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while((!s.empty())&& (prec(infix[i]) <=prec(s.top())))
                    {
                        post+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                
            }
            
        }
    }
    while(!s.empty())
    {
        post+=s.top();
        s.pop();
    }
    return post;
}
int main()
{
    string infix_exp, postfix_exp;
  	cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix_exp;
  	stack <char> stack;
    cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = InfixToPostfix(stack, infix_exp);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
    
   
    return 0;
}
