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
Various versions of paranthesis matching
1. General checking
2. Ascii comparision
*/

// 1. General checking
/*
int main()
{
    string s = "{()}[]]";
    int i = 0;
    stack<char> st;
    while(s[i]!='\0')
    {
        char ch = st.empty()?'#':st.top(); // if st is empty then ch is some char #
        if(ch=='(' && s[i] == ')')
        {
            st.pop();
        }
        else if(ch=='{' && s[i] == '}')
        {
            st.pop();
        }
        else if(ch=='[' && s[i] == ']')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }
    cout << st.empty() << endl;
}

*/

// 2. Ascii comparision

bool isBalanced(string s)
{
    stack<char> st;
    int i = 0;
    while(s[i]!='\0')
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }
            else if(s[i]-st.top()==1 || s[i]-st.top()==2)
            {
                st.pop();
            }
            else 
            {
                return false;
            }
        }
        i++;
    }
    return st.empty();
}

int main()
{
    string s = "{()}[]]";
    cout << isBalanced(s);
}

