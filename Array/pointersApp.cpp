#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

/*
int main()

{
    int n ;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    const int N = 1000;
    int indexArray[N];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++)
    {
        indexArray[i] = -1;
    }

    int minIndex = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(indexArray[arr[i]] != -1)
        {
            minIndex = min(minIndex, indexArray[arr[i]]);
        }
        else
        {
            indexArray[arr[i]] = i;
        }
    }    
    cout << minIndex+1 << endl;

}

*/

// Pointers basics, arithmatics, pointer to array, pointer to pointer
/*
int main()

{
    int a = 10;
    int *p = &a;
    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << "---------------------" << endl;

    a = 15;
    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << "---------------------" << endl;

    *p = 20;
    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << "---------------------" << endl;

    // pointer to array
    int arr[] = {10,20,30,40};
    cout << arr << endl;
    cout << *(arr) << endl;
    cout << (arr+1) << endl; 
    // arr++ is illegal as arr is an address not an integer or dereferencer.
    cout << *(arr+1) << endl;

    // Pointer to pointer
    int b = 15;
    int *p2 = &b;
    int **q = &p2;

    cout << b << endl;
    cout << p2 << endl;
    cout << *p2 << endl;
    cout << q << endl;
    cout << *q << endl;
    cout << **q << endl;
    cout << "------------------" << endl;
    **q = 25;
    cout << b << endl;
    cout << p2<< endl;
    cout << *p2 << endl;
    cout << q << endl;
    cout << *q << endl;
    cout << **q << endl;
    cout << "------------------" << endl;

}

*/

