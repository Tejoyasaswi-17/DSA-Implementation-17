#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <stack>
using namespace std;

/* Reverse a stack
1. Reversing a stack can be done in two ways one is using another new stack and just popping from one and pushing in another
2. Another way is to simply use recursion
*/

void insertAtBottom(stack<int> &st, int x)
{
    // This is again a recursive function
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int el = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(el);
}

void recReverse(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int el = st.top();
    st.pop();
    recReverse(st);
    insertAtBottom(st, el);
}

int main()
{
    stack<int> st;
    st.push(2);
    st.push(1);
    st.push(3);
    recReverse(st);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}