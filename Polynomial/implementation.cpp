#include <iostream>
#include <cmath>
#include <math.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class term
{
    public:
    int coeff;
    int exp;
};

class Polynomial
{
    public:
    int n; // no of terms
    term *t;

    Polynomial(int n)
    {
        this->n = n;
        t = new term[this->n];
    }
    ~Polynomial()
    {
        delete [] t;
    }
    Polynomial operator+(Polynomial &p);
    friend istream & operator>>(istream &ip, Polynomial &p);
    friend ostream & operator<<(ostream &op, Polynomial &p);
};
    istream & operator>>(istream &ip, Polynomial &p)
    {
        for(int i = 0; i < p.n; i++)
        {
            cin >> p.t[i].coeff >> p.t[i].exp;
        }
        return ip;
    }
    ostream & operator<<(ostream &op, Polynomial &p)
    {
        for(int i = 0; i < p.n; i++)
        {
            if(i!=p.n-1)
            {
                cout << p.t[i].coeff << "x" << p.t[i].exp << "+";
            }
            else
            {
                cout << p.t[i].coeff << "x" << p.t[i].exp;
            }  
        }
        cout << endl;
        return op;
    }
    Polynomial Polynomial::operator+(Polynomial &p)
    {
        Polynomial *sum = new Polynomial(n+p.n);
        int i, j, k;
        i = j = k = 0;
        while(i<n && j<p.n)
        {
            if(t[i].exp > p.t[j].exp)
            {
                sum->t[k++] = t[i++];
            }
            else if(t[i].exp < p.t[j].exp)
            {
                sum->t[k++] = p.t[j++];
            }
            else
            {
                sum->t[k].exp = t[i].exp;
                sum->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
            }
        }
        for(;i<n;i++)
        {
            sum->t[k++] = t[i];
        }
        for(;j<p.n;j++)
        {
            sum->t[k++] = p.t[j];
        }
        sum->n = k;
        return *sum;
    }

int main()
{
    Polynomial p1(5);
    Polynomial p2(4);
    cin >> p1;
    cout << "First polynomial: ";
    cout << p1;
    cin >> p2;
    cout << "Second polynomial: ";
    cout << p2;
    Polynomial p3 = p1+p2;
    cout << "Sum of polynomials implies" << endl;
    cout << p3 ;
}