#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <climits>
#include <math.h>
using namespace std;

int euclidGCD(int a, int b)

{
    while(1)
    {
        int c = (a-b >= 0) ? a-b : b -a;
        if(c==0)
        {
            return a;
        }
        a = (a <= b) ? a : b;
        b = c;
    }
}

int main()

{
    int a, b;
    cin >> a >> b;
    cout << euclidGCD(a, b) << endl;
}