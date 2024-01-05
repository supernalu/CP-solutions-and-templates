//https://pl.spoj.com/problems/BICAKE/
#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long n;
    
    while (cin >> n)
    {
        long long i = 1; 
        long long j = 0;
        while (i < n)
        {            
            i+=j+1;  
            ++j;          
        }
        cout << j << '\n';
    }
}