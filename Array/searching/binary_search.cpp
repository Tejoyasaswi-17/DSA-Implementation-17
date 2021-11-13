/*
Contents of this file - binary search and its applications.
1. Iterative version of binarySearch
2. Recursive version of binarySearch
3. First and last occurence of an element using binarySearch
4. Count of a given element in an array
5. No of times a sorted array is rotated.
6. Searching an element in a circularly sorted array.
*/

//Binary search: Searching for an element in sorted array by repeatedly dividing the search space in half.
// Binary search: This is a time effecient searching method where in we tranform array to half the size everytime and finally find the element in lesser time when compared to linear search
// But the main drawback of this method is it is applicable only when the array is sorted
// Typical implementation of divide and conquer algorithm

// Time complexity: O(log2 N)
// Space complexity: O(N)

#include <iostream>
#include <math.h>
using namespace std;

// 1. Iterative version
/*
int binarySearch(int array[], int n, int key)
{
    int start = 0;
    int end = n;
    while(start <= end)
    {
        int mid = start +(end-start)/2; // To avoid the overflow caused by (start+end)
        if(array[mid] == key)
        {
            return mid;
        }
        else if(array[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
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
    cout << binarySearch(arr, n, key) << endl;
}
*/

// 2. Recursive version
/*
int binarySearch(int array[], int start, int end, int key)
{
    if(start>end)
    {
        return -1;
    }
    int mid = start +(end-start)/2;
    if(array[mid] == key)
    {
        return mid;
    }
    else if(array[mid] > key)
    {
        return binarySearch(array,start, mid-1,key);
    }
    else
    {
        return binarySearch(array,mid+1, end,key);
    }

}

int main()
{
    int arr[]{1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 8;
    cout << binarySearch(arr, 0,n,key) << endl;
}
*/

//3. First and last occurence of an element(2 in one function)
/*
int FirstOrLastOccurence(int arr[], int n, int key, bool firstOcc)
{
    int result=-1;
    int start =0, end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid] > key)
        {
            end = mid-1;
        }
        else if(arr[mid] < key)
        {
            start = mid+1;
        }
        else
        {
            result = mid;
            if(firstOcc)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
    }
    return result;
}

int main()
{
    int arr[]{1,2,3,4,4,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 10;
    cout << "first: " << FirstOrLastOccurence(arr, n,key, true) << endl;
    cout << "last: " << FirstOrLastOccurence(arr, n,key, false) << endl;
}
*/
// 4. Count of a given element in an array
// This can be done by using binary search that is calculate first, last occurences of given element, return (lastOcc-firstOcc+1)


// 5. No of times a sorted array is rotated.
// Given a circularly sorted array with no duplicates find out how many times is the array rotated.
// Brute force is simply traversing through the array and returning the index of minimum element.
// Optimised way is by using binary search

/*
int timesRotated(int arr[], int n)
{
    int start = 0, end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[start] < arr[end])
        {
            return start;
        }
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            //pivot element
            return mid;
        }
        if(arr[mid] >= arr[end])
        {
            start = mid+1;
        }
        else if(arr[mid] <= arr[end])
        {
            end = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]{11,12,15,18,2,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << timesRotated(arr, n) << endl;
}
*/

// 6. Searching an element in a circularly sorted array

int searchElem(int arr[], int n, int key)
{
    int start = 0, end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        if(arr[mid] <= arr[end])// Right half is sorted
        {
            if(key>arr[mid] && (key<=arr[end]))
            {
                start = mid+1;//Search in right half
            }
            else
            {
                end = mid-1; //search in left half
            }
        }
        else // Left half is sorted
        {
            if(key>=arr[start] && key<arr[mid])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[]{11,12,15,18,2,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++)
    {
        int key = arr[i];
        cout << searchElem(arr, n, key) << endl;
    }
    //cout << searchElem(arr, n, 11) << endl;
    
}