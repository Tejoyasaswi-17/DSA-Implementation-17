// Bubble sort is another algorithm in which we repetedly swap adjacent elements if they are in wrong order
// In this alg for every loop the highest element of unsorted part gets bubbled to the end

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
    for(int i = 1 ; i < n; i++)
    {
        bool swapped = false;
        for(int j = 0; j < n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }

}




