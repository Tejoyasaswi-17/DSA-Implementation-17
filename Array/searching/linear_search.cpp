// Linear search : This is one by one search. The loop traverses through the complete array and breaks wherever it finds the key
// Time complexity: O(N)
// Space complexity: O(N)

// This function searches the array using the linear search algorithm and return index if found or else returns -1

#include <iostream>
#include <math.h>
using namespace std;

int linearSearch(int array[], int n, int key)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(array[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()

{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n] {};
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    cout << linearSearch(arr, n, key) << endl;
}