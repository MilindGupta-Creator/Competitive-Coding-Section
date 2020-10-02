/*
Problem - Parenthesis Checker
Platform- GFG
Time Complexity-O(N)
Author Adarsh
*/

bool ispar(string x)
{
    stack<char> s;
    s.push('x');
    for(int i=0;i<x.size();i++)
    {
        if(x[i]==')')
        {
            if(s.top()=='(')
            {
                s.pop();
            }
            else{
                return false;
            }
        }
        else if(x[i]=='}')
        {
            if(s.top()=='{')
            {
                s.pop();
            }
            else{
                return false;
            }
        }
        else if(x[i]==']')
        {
            if(s.top()=='[')
            {
                s.pop();
            }
            else{
                return false;
            }
        }
        else{
            s.push(x[i]);
        }
    }
    if(s.top()=='x')
    {
        return true;
    }
    else{
        return false;
    }
    
}
