/*
Contents of this file
1. Maximum subarray sum (1.Brute force, 2.Cumulative sum approach, 3.Kadane's algorithm)
2. Maximum circular subarray sum
*/
#include <iostream>
#include <cmath>
#include <math.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;

/* Basic brute force

int main()

{
    int n ;
    cout << "Please enter the value of n";
    cin >> n;
    int maxSum = INT_MIN;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n ; i++)
    {
        for(int j = i ; j <n ; j++)
        {
            int sum = 0;
            for (int k = i ; k <= j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }  
    }
    cout << maxSum << endl;
}

*/

// Cumulative sum approach


/*
int main()

{
    int n ;
    cout << "Please enter the value of n";
    cin >> n;
    int maxSum = INT_MIN;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int currSum[n+1];
    currSum[0] = 0;
    for(int i = 1 ; i <= n; i++)
    {
        currSum[i] = arr[i-1] + currSum[i-1];
    }
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 0; j < i ; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum << endl;
}

*/

// Kadane's algorithm

/*
int main()

{
    int n ;
    cout << "Please enter the value of n";
    cin >> n;
    int maxSum = INT_MIN;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int currSum = 0;
    for(int i = 0 ; i < n; i++)
    {
        currSum = currSum + arr[i];
        if(maxSum < currSum)
        {
            maxSum = currSum;
        }
        if(currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << maxSum << endl;
}
*/



// 2. Maximum circular subarray sum

/*
// Function which outputs the maximum subarray sum
int kadane(int arr[], int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i =0; i< n; i++)
    {
        currSum = currSum + arr[i];
        if(maxSum < currSum)
        {
            maxSum = currSum;
        }
        if(currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

// Function which outputs the sum of the array
int sum(int arr[], int n)
{
    int sum_arr = 0;
    for(int i =0; i< n; i++)
    {
        sum_arr+=arr[i];
    }
    return sum_arr;
}


int main()

{
    int n ;
    cout << "Please enter the size of array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int wrapSum = 0;
    int nonWrapSum = kadane(arr, n);
    int arrTemp[n];
    for(int i =0; i<n; i++)
    {
        arrTemp[i] = -1 * arr[i];
    }
    wrapSum = sum(arr, n) + kadane(arrTemp, n);
    cout << max(wrapSum, nonWrapSum) << endl;

}
*/

