// Sorting is nothing but arranging the elements in ascending order(Generally)
// There are many algorithms for sorting.
// In this algorithm array is sorted repeatedly finding the minimum element from the unsorted part and moving it to the sorted part.

// Time complexity: O(N^2)


#include <iostream>
#include <math.h>
#include <climits>
using namespace std;



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
    for(int i = 0 ; i < n-1 ; i++)
    {
        int min = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
}