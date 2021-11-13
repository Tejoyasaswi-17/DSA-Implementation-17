/*
Contents of this file
1. Sieve of Eratosthenes(Finding prime numbers before a given number)
2. Prime factorization using sieve
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <climits>
#include <math.h>
using namespace std;

// 1. A simple way for finding the prime numbers before a given number

/*

void primeSieve(int n)
{
    int primeArr[n+1]={0};
    for(int i = 2; i <= n; i++)
    {
        if(primeArr[i] == 0)
        {
            for(int j = i*i; j <= n; j+=i)
            {
                primeArr[j] = 1;
            }
        }
    }

    for(int i = 2; i <= n ; i++)
    {
        if(primeArr[i] == 0)
        {
            cout << i << " ";
        }
    }

}

int main()
{
    int n;
    cout << "Enter the number: " ;
    cin >> n;
    primeSieve(n);
}

*/

// 2. Prime factorization using sieve

void primeFactors(int n)
{
    //spf means smallest prime factor
    int spf[n+1] = {0};
    for(int i =2; i <=n ; i++)
    {
        spf[i] = i;
    }
    for(int i =2; i<= n; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i*i; j <=n; j+=i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    while(n!=1)
    {
        cout << spf[n] << " ";
        n = n/spf[n];
    }
}

int main()

{
    int n;
    cin>> n;
    primeFactors(n);
}
