/*
Contents of this file
1. Palindrome check
2. Biggest word in the sentence
*/
#include <iostream>
#include <cmath>
#include <math.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// 1. Palindrome check

/*

int main()

{
    int n;
    cin >> n;
    char arr[n+1];
    cin >> arr;
    bool check = true;
    int i =0;
    while(arr[i] != '\0' && check)
    {
        if(arr[i] != arr[n-i-1])
        {
            check = false;
        }
        i++;
    }
    if(check)
    {
        cout << "Yes it is " << endl;
    }
    else
    {
        cout << "No its not a palindrome" << endl;
    }
}

*/

// 2. Biggest word in the sentence

int main()

{
    int n;
    cin >> n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();
    int currLen = 0, maxLen = 0;
    int i = 0;
    int st = 0, maxst = 0;
    while(true)
    {
        if(arr[i] == '\0' || arr[i] == ' ')
        {
            if(currLen > maxLen)
            {
                maxLen = currLen ;
                maxst = i;
                st = i - maxLen;
            }
            currLen = 0;
        }
        else
        {
            currLen++;
        }
        if(arr[i] == '\0')
        {
            break;
        }
        i++;
    }
    char bigWord[maxLen+1];
    for(int i = 0; i < maxLen; i++)
    {
        bigWord[i] = arr[st+i];
    }
    cout << maxLen << endl;
    cout << bigWord << endl;
}