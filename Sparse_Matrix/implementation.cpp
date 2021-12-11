#include <iostream>
#include <cmath>
#include <math.h>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class element
{
    public:
    int i; //row no.
    int j; //col no.
    int x;//element itself
};

class sparse
{
    private:
    int m; //dimension
    int n;
    int num;//no.of non zero elements
    element *el;
    public:
    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        el = new element[this->num];
    }
    ~sparse()
    {
        delete [] el;
    }
    sparse operator+(sparse &s);
    friend istream & operator>>(istream &is, sparse &s);
    friend ostream & operator<<(ostream &os, sparse &s);
};
    istream & operator>>(istream &is, sparse &s)
    {
        //for reading all non zero elements
        for(int i = 0; i < s.num; i++)
        {
            cin>>s.el[i].i >> s.el[i].j >> s.el[i].x;
        }
        return is;
    }
    ostream & operator<<(ostream &os, sparse &s)
    {
        int k = 0;
        for(int i = 0; i < s.m; i++)
        {
            for(int j = 0; j < s.n; j++)
            {
                if((s.el[k].i == i) && (s.el[k].j == j))
                {
                    cout << s.el[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return os;
    }
    sparse sparse::operator+(sparse &s)
    {
        if(m!=s.m || n!=s.n)
        {
            return sparse(0,0,0);
        }
        sparse *sum = new sparse(m,n,m+n);
        int i, j , k;
        i = j = k = 0;
        while(i<num && j<s.num)
        {
            if(el[i].i < s.el[j].i)
            {
                sum->el[k++] = el[i++];
            }
            else if(el[i].i > s.el[j].i)
            {
                sum->el[k++] = s.el[j++];
            }
            else
            {
                if(el[i].j < s.el[j].j)
                {
                    sum->el[k++] = el[i++];
                }
                else if(el[i].j > s.el[j].j)
                {
                    sum->el[k++] = s.el[j++];
                }
                else
                {
                    sum->el[k] = el[i];
                    sum->el[k++].x = el[i++].x + s.el[j++].x;
                }
            }
        }
        for(;i<num;i++)
        {
            sum->el[k++] = el[i];
        }
        for(;j<s.num;j++)
        {
            sum->el[k++] = el[j];
        }
        sum->m = m;
        sum->n = s.n;
        sum->num = k;
        return *sum;
    }

int main()
{
    sparse s1(5,5,5);
    sparse s2(5,5,6);
    cin>>s1;
    cout<<s1;
    cin>>s2;
    cout<<s2;
    sparse sum = s1+s2;
    cout << sum;
}