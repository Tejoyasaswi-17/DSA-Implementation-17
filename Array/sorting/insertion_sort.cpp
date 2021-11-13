//Insert an element from unsorted array to its right position in sorted array
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
    for(int i = 1 ; i < n ; i++)
    {
        int currValue = arr[i];
        for(int j = i-1 ; j >= 0 ; j--)
        {
            if(currValue < arr[j])
            {
                arr[j+1] = arr[j];
                arr[j] = currValue;
            }
        }
        /*for(int j = i-1; j>=0; j--)
        {
            if(currValue < arr[j])
            {
                swap(arr[j+1], arr[j]);
            }
        }*/
    }
    cout << "Sorted matrix" << endl;
    for(int i = 0 ; i < n; i++)
    {
        cout << arr[i] << endl;
    }

}