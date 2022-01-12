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

// Space effecient implementation of k stacks in an array

class kStacks
{
    int *arr; // arr in which k stacks are implemented
    // In arr along with k stacks a stack of free slots is also maintained, top of this stack is stored in variable called free
    int *top; // Arr of size k to maintain the top element of all stacks
    int *next; // Arr of size n to store the indexes of next item for items in arr
    int n,k,free; // free is to store the beginning of free list

    public:
    kStacks(int k, int n);
    bool isFull()
    {
        return (free==-1);
    }
    bool isEmpty(int sn)
    {
        return (top[sn]==-1);
    }
    void push(int num, int sn); // To push an item in stack sn
    int pop(int sn); // To pop an element from stack sn

};

kStacks::kStacks(int k1, int n1)
{
    k = k1, n= n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    // Initialise all stacks as empty that means top pointer is at index = -1
    for(int i = 0; i < k; i++)
    {
        top[i]=-1;
    }
    free = 0;
    // Next should point to the next element
    for(int i = 0; i < n-1; i++)
    {
        next[i]=i+1;
    }
    next[n-1] = -1 // End of free list
}

void kStacks::push(int num, int sn)
{

}

int main()
{

}