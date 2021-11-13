//This algorithm is better than quick and merge sort in terms of time complexity
// Time complexity is O(max(Arr[i], n))

// 1. Find the count of every distinct element in the array
// 2. Calculate the position of each element in sorted array
// Workflow Array--> Count Array---> Cum Count Arr--->New Arr.

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <climits>
#include <algorithm>
using namespace std;

// This below method is not applicable in case of negative numbers

/*

void countSort(int *arr, int n)
{
    int k = arr[0];
    for(int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }
    int countArr[k+1] = {0};
    for(int i = 0; i < n; i++)
    {
        countArr[arr[i]]++;
    }
    for(int i = 1; i <= k ; i++)
    {
        countArr[i] += countArr[i-1];
    }
    int output[n]{0};
    for(int i = n-1; i >= 0; i--)
    {
        int p = arr[i];
        output[(--countArr[p])] = p;
    }
    for(int i = 0; i < n ; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] {1,3,2,3,4,1,6,4,3,15,20,28,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
}

*/

// Method applicable for both positive and negative numbers is 

void countSort(int *arr, int n)
{
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    int range = max-min+1;
    int countArr[range] = {0};
    for(int i = 0; i < n; i++)
    {
        countArr[arr[i]-min]++;
    }
    for(int i = 1; i < range; i++)
    {
        countArr[i]+=countArr[i-1];
    }
    int output[n]{0};
    for(int i = 0; i < n; i++)
    {
        output[--countArr[arr[i]-min]] = arr[i];
    }
    for(int i = 0; i < n ; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] {-1,5,6,3,2,-4,16,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
}