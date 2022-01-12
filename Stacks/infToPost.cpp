#include <iostream>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

/* 
Contents of this file
1. Infix to postfix conversion
2. Evaluating a postfix expression
*/

bool isOperand(char ch)
{
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '(' || ch == ')' || ch =='^')
    {
        return false;
    }
    return true;
}

int outprec(char ch)
{
    if (ch == '+' || ch == '-'){
        return 1;
    } else if (ch == '*' || ch == '/'){
        return 3;
    } else if (ch == '^'){
        return 6;
    } else if (ch == '('){
        return 7;
    } else if (ch == ')'){
        return 0;
    }
    return -1;
}

int inprec(char ch)
{
    if (ch == '+' || ch == '-'){
        return 2;
    } else if (ch == '*' || ch == '/'){
        return 4;
    } else if (ch == '^'){
        return 5;
    } else if (ch == '('){
        return 0;
    }
    return -1;
}

string infixToPostfix(string s)
{
    stack<char>st;
    string postfix = "";
    int i = 0;
    while(s[i] != '\0')
    {
        if(isOperand(s[i]))
        {
            postfix+=s[i++];
        }
        else
        {
            if(!st.empty() && outprec(s[i]) < inprec(st.top()))
            {
                postfix+=st.top();
                st.pop();
            }
            else if(!st.empty() && outprec(s[i]) == inprec(st.top()))
            {
                st.pop();
            }
            else
            {
                st.push(s[i++]);
            }
        }
    }
    while(!st.empty() && st.top()!=')')
    {
        char ch3 = st.top();
        postfix+=ch3;
        st.pop();
    }
    return postfix;
}

int applyArith(char ch, int a, int b)
{
    int byVar;
    if(ch=='+')
    {
        byVar = a+b;
    }
    else if(ch=='-')
    {
        byVar = a-b;
    }
    else if(ch=='*')
    {
        byVar = a*b;
    }
    else if(ch=='/')
    {
        byVar = a/b;
    }
    else if(ch=='^')
    {
        byVar = pow(a,b);
    }
    return byVar;
}

int postCalc(string s)
{
    stack<int>st;
    int ans;
    int i = 0;
    while(s[i]!='\0')
    {
        if(isOperand(s[i]))
        {
            st.push(s[i]-'0');
        }
        else
        {
            int left, right;
            right = st.top();
            st.pop();
            left = st.top();
            st.pop();
            int byAns = applyArith(s[i], left, right);
            st.push(byAns);
        }
        i++;
    }
    ans = st.top();
    return ans;
}

int main()
{
    string s = "((a+b)*c)-d^e^f";
    string res = infixToPostfix(s);
    cout << res << endl;
    string s2 = "35*62/+4-";
    int ans = postCalc(s2);
    cout << ans << endl;
}