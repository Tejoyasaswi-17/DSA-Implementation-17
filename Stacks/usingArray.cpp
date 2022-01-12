#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

// The disadvantage of using array in implementation of stack is size limitation. Once the size is declared it can't be changed.

class Stack
{
    private:
    int size;
    int top;
    int *S;

    public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        S = new int[this->size];
    }

    void push(int x);
    int pop();
    void Display();
    int peek(int pos);
    bool isEmpty();
    bool isFull();
};

void Stack::push(int x)
{
    if(top == size-1)
    {
        cout << "Stack is full" << endl; // We can't add further
    }
    else
    {
        top++;
        S[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if(top == -1)
    {
        cout << "Stack is empty" << endl; // We Can't remove further
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

void Stack::Display()
{
    for(int i = top; i >= 0; i--)
    {
        cout << S[i] << " ";
    }
    cout << endl;
}

int Stack::peek(int pos)
{
    // 1-indexed when peeked from top and 0-indexed with respect to array that formed the stack
    if(pos<0 || top-pos+1<0)
    {
        return -1;
    }
    else
    {
        return S[top-pos+1];
    }
}

bool Stack::isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

bool Stack::isFull()
{
    if(top==size-1)
    {
        return true;
    }
    return false;
}

int main()
{
    int size, a;  // Here this works on the principle of LIFO(Last in is the first out)
    cout << "Enter the size: ";
    cin >> size;
    Stack st(size);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.Display();
    st.pop();
    st.Display();
    cout << st.peek(2) << endl;
}