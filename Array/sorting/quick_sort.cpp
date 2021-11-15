// This is most effecient algorithm in practical scenarios and its implementation can be seen in sort function of various language
// Time complexity depends on the selection of pivot element.
// Randomised partition is used here in order to avoid the worst case by randomly choosing any element from array 
// and swapping it with the last one. So worst case probability reduces approximately to zero.
// This algorithm has no need for creating auxillary arrays.

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

int Partition(int *A, int start, int end)
{
    int Pindex = start;
    int pivot = A[end];
    for(int i = start; i < end; i++)
    {
        if(A[i] <= pivot)
        {
            swap(A[i],A[Pindex]);
            Pindex++;
        }
    }
    swap(A[Pindex], A[end]);
    return Pindex;
}

int RandomisedPartition (int *A, int start, int end)
{
    int pivotindex = start + (rand() % (end-start+1));
    swap(A[pivotindex],A[end]);
    int Pindex = Partition(A, start, end);
    return Pindex;
}


void QuickSort(int *A, int start, int end)
{
    if(start<end)
    {
        int Pindex = RandomisedPartition(A, start, end);
        QuickSort(A, start, Pindex-1);
        QuickSort(A, Pindex+1, end);
    }
}

int main()

{
    int arr[]{1,6,2,3,4,5,9,0};
    int end = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    QuickSort(arr, start, end-1);
    for(int i = 0; i< end; i++)
    {
        cout << arr[i] << " ";
    }
}
