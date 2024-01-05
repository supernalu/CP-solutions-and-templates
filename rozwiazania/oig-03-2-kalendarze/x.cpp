#include <bits/stdc++.h>

constexpr int MAXN = 1e5 + 10;

using namespace std;

int n[2], q;

int a[2][MAXN];

int pref[2][MAXN];

int main()
{
    cin >> n[0] >> n[1];

    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n[0]; i++)
        {
            cin >> a[j][i];
        }
    }

    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n[1]; i++)
        {
            pref[j][i] = a[j][i] + pref[j][i-1]; 
        }
    }

    cin >> q;

    while(q--)
    {
        int a, b, d;

        char c;

        cin >> a >> b >> c;

        if (c == 'A')
            d = 1;
        else
            d = 0;

        for (int i = 1; i <= n[(d+1)%2]; i++)
        {
            
        }        
    }


    



}