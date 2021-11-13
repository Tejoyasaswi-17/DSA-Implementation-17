/*
Contents of this file
1. Spiral order matrix traversal
2. Transpose of a matrix
3. Matrix multiplication
4. 2D Array search
*/
#include <iostream>
#include <cmath>
#include <math.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;


// 1. Spiral order matrix traversal

/*

bool checkInRange(int a, int b, int c, int d)
{
    if(a <= b && c <= d)
    {
        return true;
    }
    return false;
}

int main()

{
    int n, m;
    cout << "Enter size of matrix: ";
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }

    int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = m-1;
    while(checkInRange(rowStart,rowEnd,colStart,colEnd))
    {
        for(int i = colStart; i <= colEnd && checkInRange(rowStart,rowEnd,colStart,colEnd); i++)
        {
            cout << arr[rowStart][i] << " ";
        }
        rowStart++;
        for(int i = rowStart; i <= rowEnd && checkInRange(rowStart,rowEnd,colStart,colEnd); i++)
        {
            cout << arr[i][colEnd] << " ";
        }
        colEnd--;
        for(int i = colEnd; i >= colStart && checkInRange(rowStart,rowEnd,colStart,colEnd); i--)
        {
            cout << arr[rowEnd][i] << " ";
        }
        rowEnd--;
        for(int i = rowEnd; i >= rowStart && checkInRange(rowStart,rowEnd,colStart,colEnd); i--)
        {
            cout << arr[i][colStart] << " ";
        }
        colStart++;
    }

}

//1 2 3 4 5 6 7 8 9 10 11 12

*/

// 2. Transpose of a matrix

/*

int main()

{
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    for(int i = 0; i < 3; i++)
    {
        for(int j = i; j < 3 ; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

*/


// 3. Matrix multiplication

/*

int main()

{
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    int m1[n1][n2];
    int m2[n2][n3];

    for(int i =0; i< n1; i++)
    {
        for(int j =0; j < n2; j++)
        {
            cin >> m1[i][j];
        }
    }
    for(int i =0; i< n2; i++)
    {
        for(int j =0; j < n3; j++)
        {
            cin >> m2[i][j];
        }
    }

    int res[n1][n3];

    for(int i = 0; i <n1; i++)
    {
        for(int j =0; j<n3; j++)
        {
            res[i][j] = 0;
        }
    }
    for(int i =0; i < n1; i++)
    {
        for(int j =0; j< n3; j++)
        {
            for(int k =0; k < n2; k++)
            {
                res[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }

    for(int i = 0; i <n1; i++)
    {
        for(int j =0; j<n3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}

*/


// 4. 2D array search

int main()

{
    int n1, n2;
    cin >> n1 >> n2;
    int arr[n1][n2];
    for(int i =0; i<n1; i++)
    {
        for(int j =0; j<n2; j++)
        {
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;
    int start_i = 0;
    int start_j = n2-1;
    bool flag = false;
    while(start_j >=0 && start_i < n1)
    {
        if(arr[start_i][start_j] > target)
        {
            start_j--;
        }
        else if (arr[start_i][start_j] < target)
        {
            start_i++;
        }
        else
        {
            flag = true;
            break;
        }
    }

    if(flag)
    {
        cout << "Found the element" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

}
