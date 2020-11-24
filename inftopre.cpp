#include <iostream>
#include<stack>
#include <algorithm>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}
 
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string InfixToPrefix(stack <char > s ,string inf)
{
    string pre;
    reverse(inf.begin(),inf.end());
     for (int i = 0; i < inf.length(); i++) {
        if (inf[i] == '(') {
            inf[i] = ')';
        }
        else if (inf[i] == ')') {
            inf[i] = '(';
        }}
    for (int i = 0; i < inf.length(); i++)
    {
        if ((inf[i]>='a' && inf[i] <='z') || (inf[i]>='A') && (inf[i] <='Z'))
        {
            pre+=inf[i];
        }
        else if( inf[i] == '(')
        {
            s.push(inf[i]);
        }
        else if(inf[i] == ')')
        {
            while((s.top()!='(') && (!s.empty()))
            {
                pre+=s.top();
                s.pop();
            }
            if(s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(inf[i]))
        {
            if(s.empty())
            {
                s.push(inf[i]);
            }
            else
            {
                 if(precedence(inf[i]) > precedence(s.top()))
            {
                s.push(inf[i]);
            }
            else if (( precedence(inf[i]) == precedence(s.top())) && (inf[i]) == '^')
            {
                while ((precedence(inf[i]) == precedence(s.top()))
                        && (inf[i] == '^')) {
                        pre += s.top();
                        s.pop();
                    }
                    s.push(inf[i]);
            }
            else if (precedence(inf[i]) == precedence(s.top()))
            {
                s.push(inf[i]);
            }
            else
            {
                 while ((!s.empty()) && (precedence(inf[i]) < precedence(s.top()))) {
                        pre += s.top();
                        s.pop();
                    }
                    s.push(inf[i]);
            }
            
            }
            
           
        }

    }
    while (!s.empty())
    {
        pre+=s.top();
        s.pop();
    }
    reverse(pre.begin(),pre.end());
    return pre;
    

}
int main()
{
     string infix, prefix;
    cout << "Enter a Infix Expression :" << endl;
    cin >> infix;
    stack<char> stack;
    cout << "INFIX EXPRESSION: " << infix << endl;
    prefix = InfixToPrefix(stack, infix);
    cout << endl
         << "PREFIX EXPRESSION: " << prefix;
    
    
   
    return 0;
}
