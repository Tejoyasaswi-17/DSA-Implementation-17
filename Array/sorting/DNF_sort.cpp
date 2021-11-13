// DNF means dutch national flag and also known as 0,1,2 sort as only three elements are present
// Time complexity is O(N)
// Only applicable if there are three distinct elements.

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

void dnfSort(int *arr, int n)
{
    int start = 0, mid = 0, end = n-1;
    while(mid <= end)
    {
        if(arr[mid] == 0)
        {
            swap(arr[start], arr[mid]);
            start++;mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid],arr[end]);
            end--;
        }
    }
}

int main()
{
    int arr[]{1,0,2,1,0,1,2,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    dnfSort(arr,n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}