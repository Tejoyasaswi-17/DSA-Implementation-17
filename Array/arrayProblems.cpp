/*
Contents of this file
1. Maximum till i in an array
2. Sum of each possible subarrays of given array
3. Sum of all subarrays for a given array using linear time complexity
4. Longest arithmatic subarray
5. Record Breaking days
6. First repeating element
7. Subarray with given sum
8. Smallest positive missing number from the array
*/
#include <iostream>
#include <cmath>
#include <math.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// 1. Maximum till position i
// Logic is to iterate through the array with till ith index included and find the maximum element

// 2. Sum of each possible subarrays of given array
// Logic is to use a nested for loop with first loop running from 0 to n and inner loop running from i to n
// At each time iterating through the inner loop print out sum.

// 3. Sum of all subarrays for a given array using linear time complexity
// Actually there is pattern behind this question simply arr[i] appears (n-i)*(i+1) times where n is size of array
// so simply we can return the sum. Sum = sigma(arr[i]*(n-i)*(i+1)) i from 0->n-1.

// 4. Longest arithamatic subarray 
// Arithmatic subarray is the subarray with prevdiff = currdiff
/*
int main()
{
    int arr[] {10,7,4,6,8,10,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int currentDiff = 0, prevDiff = 0, maxLength =1, p =0;
    prevDiff = arr[1] - arr[0];
    for(int i = 1; i < n-1; i++)
    {
        currentDiff = arr[i+1] - arr[i];
        if(currentDiff == prevDiff)
        {
            maxLength += 1;
        }
        else
        {
            prevDiff = currentDiff;
            p = max(p,maxLength);
            maxLength = 2;
        }
    }
    cout << p << endl;
}
*/
// 5. Record breaking days 
/*
int main()
{
    int arr[] { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int recBreakDays = 0;
    int prevMax = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        //Check whether it is last day
        if(i==n-1)
        {
            if(arr[i]>prevMax)
            {
                recBreakDays++;
            }
        }
        else if (arr[i]>prevMax && arr[i] > arr[i+1])
        {
            recBreakDays++;
        }
        prevMax = max(prevMax, arr[i]);
    }
    cout << recBreakDays << endl;
}
*/

// 6. First repeating element index
// Here the answer is said with respect to zero indexing.
/*
int main()
{
    int arr[]{1,5,3,4,3,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    int indexArray[max+1];
    for(int i = 0; i <= max; i++)
    {
        indexArray[i] = -1;
    }
    int minIndex = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(indexArray[arr[i]] != -1)
        {
            minIndex = min(minIndex, indexArray[arr[i]]);
        }
        else
        {
            indexArray[arr[i]] = i+1;
        }
    }    
    cout << minIndex << endl;
}
*/

// 7. Subarray with given sum
// This problem can be solved in linear time using two pointer method.
/*
int main()
{
    int arr[] { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    int S= 23, i = 0;
    int start = i, end = n, subarraySum =0;
    while(start < end)
    {
        subarraySum += arr[start];
        if(subarraySum != S && start == n-1)
        {
            i++;
            start = i;
            subarraySum = 0;
            continue;
        }
        if(subarraySum == S)
        {
            cout << i+1 << " " << start+1 << endl;
            return 0;
        }
        start++;
    }
    cout << -1 << endl;
}
*/
// 8. Smallest missing positive number
// This can be solved using frequency array method
/*
int main()
{
    int arr[] {0,1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxArr = INT_MIN;
    for(int i =0; i < n ; i++)
    {
        if(arr[i] > maxArr)
        {
            maxArr = arr[i];
        }
    }
    bool truthArray[maxArr+1];
    for(int i =0; i<=maxArr; i++)
    {
        truthArray[i] = false;
    }
    for(int i =0; i < n ; i++)
    {
        if(arr[i] >= 0)
        {
            truthArray[arr[i]] = true;
        }
    }
    int ans = -1; // Some index which is not possible in arrays
    for(int i = 1 ; i <= maxArr; i++)
    {
        if(truthArray[i] == false)
        {
            ans = i;
            
            break;
        }
    }
    if(ans!=-1)
    {
        cout << ans << endl;
    }
    else
    {
        cout <<-1 << endl;
    }
    
}
*/

// 9. Printing all the possible subarrays
/*
int main()
{
    int arr[]{-1,4,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int st = 0,end = n-1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            for(int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}
*/

// 10. Pair sum using less time complexity
/*
bool pairSum(int arr[], int n, int k)
{
    int low = 0;
    int high = n-1;
    while(low<high)
    {
        if(arr[low] + arr[high] < k)
        {
            low++;
        }
        else if(arr[low] + arr[high] > k)
        {
            high--;
        }
        else
        {
            cout << low << " " << high << endl;
            return true;
        }
    }
    return false;
}

int main()

{
    int arr[] = {2,4,7,11,14,17,20,21};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 31;
    cout << pairSum(arr, n, k) << endl;
}
*/