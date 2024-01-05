#include <bits/stdc++.h>

constexpr int MAXN = 1e6 + 10;

int n = 0;

long long fenwick[10*MAXN];

int q;



long long fenwickSum(int x)
{
    long long s = 0;
 
    while (x > 0)
    {
        s += fenwick[x];
 
        int j = x & -x;
 
        x -= j;       
    }
 
    return s;
}

long long fenwickUpdate(int k, int u)
{ 
    //std::cout << n << std::endl;


    while(k <= 10*MAXN)
    {
        fenwick[k] += u;
 
        int j = k & -k; 
 
        //std::cout << j << ' ';       
 
        k += j;
 
        
    }
}

void inicjuj(int m)
{
    q = m;
}


void dodaj(int k)
{
    n++;

    fenwickUpdate(n, k);
}

void koryguj(int i, int k)
{
    fenwickUpdate(n-i + 1, k);
}

long long suma(int i)
{
    //std::cout << std::max(n - i, 0) << std::endl;

    return fenwickSum(n) - fenwickSum(std::max(n - i, 0));
}









