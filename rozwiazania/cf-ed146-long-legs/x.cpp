#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int f(int k)
{
    return k-1+(a+k-1)/k+(b+k-1)/k;
}
int main()
{
    cin >> t;  
    while (t--)
    {
        cin >> a >> b;
        if (a < b)
            swap(a,b);   
        int res = 2e9 + 10; 
        for (int i = 1; i <= min(a, 1000000); i++)
            res = min(f(i), res);
            
        cout << res << '\n';        
    }
}