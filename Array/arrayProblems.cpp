/*
Contents of this file
1. Max till i
2. Recursive version of binarySearch
3. First and last occurence of an element using binarySearch
*/
#include <iostream>
#include <cmath>
#include <math.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/*
int maxTilli(int arr[], int n , int i)
{
    int maximum = INT_MIN;
    for(int j = 0 ; j <= i; j++)
    {
        if(arr[j] > maximum)
        {
            maximum = arr[j];
        }

    }
    return maximum;
}

int main()

{
    int arr[] {0,-9,1,3,-4,5,7};
    for(int k = 0; k <= 6; k++)
    {
        int max_till_i = maxTilli(arr,7, k);
        cout << max_till_i << endl;
    }
    
}

*/

/*
int main()

{
    int arr[] {1,1,2,2};
    for(int i = 0 ; i < 4; i++)
    {
        int sub_array_sum = 0;
        for(int j = i ; j < 4 ; j++)
        {
            sub_array_sum += arr[j];
            cout << sub_array_sum << endl;
        }
        
    }
}

*/
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

/*
int main()

{
    int arr[] {1,2,0,7,2,0,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int recBreakDays = 0;
    int maxTill_i = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i]>arr[i+1] && arr[i] > maxTill_i)
        {
            recBreakDays+=1;
        }
        maxTill_i = max(maxTill_i, arr[i]);
    }
    cout << recBreakDays << endl;
}

*/





// First repeating element index

/*
int main()
{
    int n ;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    const int N= 1e6+2;
    int indexArray[N];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++)
    {
        indexArray[i] = -1;
    }

    int minIndex = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(indexArray[arr[i]] != -1)
        {
            minIndex = min(minIndex, indexArray[arr[i]]);
        }
        else
        {
            indexArray[arr[i]] = i;
        }
    }    
    cout << minIndex << endl;
}

*/

/*

// Subarray with given sum

int main()

{
    int arr[] {1,2,3,8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int S;
    cout << "Enter the required sum of the subarray: ";
    cin >> S;
    int i = 0;
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
            break;
        }
        start++;
    }

}

*/

// Smallest missing positive number
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
    int ans = -1; // Some index which is not possible in cpp arrays
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

// Pair sum using less time complexity

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
