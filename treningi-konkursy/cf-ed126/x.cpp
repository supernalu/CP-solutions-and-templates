#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 32768;

int t;

int n;

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    for (int i = 0; i < MAXN; i++)
    {
        int j = i;

        while (j != 0)
        {
            res[i]++;

            j *= 2; 

            j %= MAXN;
        }

        
        //cout << res[i] << ' ';      
    }

    while (t--)
    {
        cin >> n;

        int re = 1e9 + 10;

        for (int i = 0; i <= 15; i++)
        {
            re = min(re, res[(n+i)%MAXN]+i);
        }

        cout << re << ' ';


    }
}