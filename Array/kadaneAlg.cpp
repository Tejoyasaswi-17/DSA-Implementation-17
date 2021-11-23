#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <climits>
#include <algorithm>
using namespace std;
/*
Contents of the file
1. Brute force for Maximum subarray sum
2. Cumulative sum approach
3. Kadane's Algorithm
4. Maximum circular subarray sum
5. Pair sum
*/

// Find the subarray in an array which has maximum sum
// This sum can be solved in multiple ways of which the best is to solve using kadane's algorithm which has O() time complexity
// 1. Brute force method
/*
int main()
{
    int arr[]{-1,4,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = (n*(n+1))/2;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            for(int k = i; k <= j; k++)
            {
                sum +=arr[k];
            }
            maxSum = max(sum,maxSum);
            
        }
    }
    cout << maxSum << endl;
}
*/
// 2. Cumulative sum approach
/*
int main()
{
    int arr[]{-1,4,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sumArr[n+1]{0};
    int maxSum = INT_MIN;
    sumArr[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sumArr[i] = arr[i-1]+sumArr[i-1];
    }
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 0; j < i; j++)
        {
            sum = sumArr[i]-sumArr[j];
            maxSum = max(sum,maxSum);
        }
    }
    cout << maxSum << endl;
}
*/
// 3. Kadane's algorithm: This is the most optimised approach for this problem
/*
int main()
{
    int arr[]{-1,4,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum = INT_MIN;
    int sumTillHere = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sumTillHere += arr[i];
        sum = arr[i];
        if(sum>sumTillHere)
        {
            maxSum = max(sum,maxSum);
            sumTillHere = sum;
        }
        maxSum = max(sumTillHere,maxSum);
    }
    cout << maxSum << endl;
}
*/
// Second version, Simple version
/*
int main()
{
    int arr[]{-1,4,-3,7,-4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSum = INT_MIN,currSum = 0;
    for(int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum,maxSum);
        if(currSum<0)
        {
            currSum = 0;
        }
    }
    cout << maxSum << endl;
}
*/
// 4. Maximum circular subarray sum

int kadane(int arr[], int n)
{
    int maxSum = INT_MIN, sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum+=arr[i];
        maxSum = max(maxSum, sum);
        if(sum<0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int maxCircularSum(int arr[], int n)
{
    int arrSum = 0;
    for(int i = 0; i < n; i++)
    {
        arrSum+=arr[i];
    }
    int tempArr[n];
    for(int i = 0; i < n; i++)
    {
        tempArr[i] = -1 * arr[i];
    }
    int nonContribSum = kadane(tempArr,n);
    int wrapSum = arrSum+nonContribSum;
    int nonWrapSum = kadane(arr,n);
    if(nonWrapSum<0)
    {
        return nonWrapSum;
    }
    return max(nonWrapSum, wrapSum);
}
int main()
{
    int a[] = {-2,-3,-1};//{ 11, 10, -20, 5, -3, -5, 8, -13, 10 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxCircularSum(a, n) << endl;
}
