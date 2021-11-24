#include <iostream>
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
1. Simple implementation of Linked List
2. Displaying a linked list
3. Adding element to the head of Linked List
4. Adding element to the tail of Linked List
5. Linear search in Linked list.
*/

class node
{
    public:
    int data;
    node* next;
    // Constructor to make our tasks easy
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    // Corner case if the head is NULL that is there are no elements in LinkedList.
    node* n = new node(val);
    if(head == NULL)
    {
        head= n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

void display(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

bool search(node* head, int key)
{
    node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head, 4);
    insertAtHead(head,5);
    display(head);
    cout << search(head, 3) << endl;
    cout << search(head, 5) << endl;
    cout << search(head, 50) << endl;
}