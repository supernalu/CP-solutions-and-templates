#include <bits/stdc++.h> 

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, p, q, x, y;

string s;

int tab[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> p >> q >> x >> y;

    cin >> s;

    tab[0] = p;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            tab[i+1] = tab[i]+1;
        }
        else
        {
            tab[i+1] = tab[i]-1;
        }
    }

    
}