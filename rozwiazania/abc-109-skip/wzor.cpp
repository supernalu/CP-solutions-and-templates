#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, x;

int p[MAXN];

int r[MAXN];

int main()
{
    cin >> n >> x;

    p[0] = x;

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    sort(p, p + n + 1);

    for (int i = 1; i <= n; i++)   
        r[i] = p[i] - p[i-1];
    /*
    for (int i = 1; i <= n; i++)
        cout << r[i] << ' ';
    cout << endl;
    */
    
    if (n == 1)
    {
        cout << r[1];
    }
    else 
    {
        
        int max = __gcd(r[1], r[2]);

        for (int i = 3; i <= n; i++)
        {
            max = __gcd(max, r[i]);
        }

        cout << max;
    }


}