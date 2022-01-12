#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
    private:
    Node* top;

    public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void Display();
    ~Stack();
};

void Stack::push(int x)
{
    Node* t = new Node(x);
    if(t == NULL)
    {
        // Unable to create new Nodes
        cout << "Heap has overflowed" << endl;
    }
    else
    {
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if(top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node* p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}

void Stack::Display()
{
    Node* p = top;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Stack::~Stack()
{
    Node* p = top;
    while(top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();
    cout << st.pop() << endl;
    st.Display();
}