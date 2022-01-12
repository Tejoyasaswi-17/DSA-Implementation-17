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
    Node* prev;
    Node* next;
    // Constructor
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class Stack
{
    private:
    Node* top;
    Node* mid;
    int size = 0;

    public:
    Stack()
    {
        top = NULL;
        mid = NULL;
    }

    void push(int x);
    void pop();
    int findMiddle();
    void deleteMiddle();
};

void Stack::push(int x)
{
    Node* t = new Node(x);
    if(size == 0)
    {
        top = t;
        mid = t;
        size++;
        return;
    }
    else
    {
        t->next = top;
        top->prev = t;
        top = t;
    }
    // Update mid if number of element is even
    if(size%2==1)
    {
        mid = mid->prev;
    }
    size++;
}

void Stack::pop()
{
    if(size!=0)
    {
        if(size == 1)
        {
            top = mid = NULL;
        }
        else
        {
            Node* t = top;
            top = top->next;
            top->prev = NULL;
            delete t;
            // Update element if the number odf elements is odd
            if(size%2==0)
            {
                mid = mid->next;
            }
        }
        size--;
    }
    
}

int Stack::findMiddle()
{
    if(size==0)
    {
        return -1;
    }
    return mid->data;
}

void Stack::deleteMiddle()
{
    Node *t = mid;
    if(size!=0)
    {
        if(size == 1)
        {
            top = mid = NULL;
        }
        else if(size == 2)
        {
            mid = mid->next;
            top->next->prev = NULL;
            top = top->next;
        }
        else
        {
            mid->next->prev = mid->prev;
            mid->prev->next = mid->next;

            if(size%2==0)
            {
                mid = mid->next;
            }
            else
            {
                mid = mid->prev;
            }
        }
        size--;
    }
}

int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.pop();
    st.pop();
    st.pop();
    cout<<st.findMiddle()<<endl;
    st.deleteMiddle();
    cout<<st.findMiddle()<<endl;
    return 0;
}