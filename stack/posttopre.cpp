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

string posttopre(string post)
{
    stack<string> s;
    for (int i = 0; i < post.length(); i++)
    {
        if(isOperand(post[i]))
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
            s.push(post[i]+op1+op2);
        }
        
    }
    return s.top();
    
}
    
    
    int main()
{
    
    
     string post, prefix;
    cout << "Enter a postFIX Expression :" << endl;
    cin >> post;
    cout << "PostFIX EXPRESSION: " << post<< endl;
    prefix = posttopre(post);
    cout << endl
         << "PREFIX EXPRESSION: " << prefix;
   
    return 0;
   
}
 
