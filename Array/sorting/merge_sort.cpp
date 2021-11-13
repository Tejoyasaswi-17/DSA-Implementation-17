/*
Contents of this file
1. Merge sort algorithm
2. Count number of inversions in an array(i.Brute force, ii.Using application of merge sort)
*/

//This is the most effecient sorting algorithm with time complexity O(nlogn) and space complexity of O(n)
//Working principle follows divide and conquer

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//1. Merge sort algorithm
/*
void Merge(int *A, int *L, int nL, int *R, int nR)
{
    int i=0, j=0, k=0;
    while(i < nL && j < nR)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<nL)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<nR)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int *A, int n)
{
    if(n<2)
    {
        return;
    }
    int mid = n/2;
    auto *L = new int[mid*sizeof(int)];
    auto *R = new int[(n-mid)*sizeof(int)];
    for(int i = 0; i < mid; i++)
    {
        L[i] = A[i];
    }
    for(int i = mid; i < n; i++)
    {
        R[i-mid] = A[i];
    }
    MergeSort(L, mid);
    MergeSort(R, n-mid);
    Merge(A, L, mid, R, n-mid);
    free(L);
    free(R); 
}


int main(void)

{
    int arr[] {2,7,3,0,9,6,17,13,12,9};
    int noOfElements = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,noOfElements);
    for(int i = 0 ; i < noOfElements ; i++)
    {
        cout << arr[i] << " ";
    }
}

*/

// 2. Count the number of inversions in a given array
// i. This is the brute force with time complexity of O(N^2)
/*
int main()
{
    int arr[]{3,5,6,9,1,2,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int inversions = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j =i+1; j<n; j++)
        {
            if(i<j && arr[i]>arr[j])
            {
                inversions++;
            }
        }
    }
    cout << inversions << endl;
}
*/
// ii.But this can be optimised using the application of merge sort
// Optimised approach with time complexity O(NlogN)

long long merge(int *arr, int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int L[n1];
    int R[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[l+i];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[mid+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            k++;i++;
        }
        else
        {
            arr[k] = R[j];
            inv += n2-i; // This is done as here a[i] > b[j] and i < j and also as ith element is greater all elements after that are equal
            k++;j++;
        }
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;k++;
    }
    return inv;
}

long long mergeSort(int *arr, int l, int r)
{
    long long inv=0;
    if(l < r)
    {
        int mid =(l+r)/2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid+1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}

int main()
{
    int arr[]{3,5,6,9,1,2,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << mergeSort(arr, 0,n-1) <<endl;
}