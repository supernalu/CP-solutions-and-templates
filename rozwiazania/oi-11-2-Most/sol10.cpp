#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

int tab[MAXN];

int res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> tab[i];
    }

    if (n == 1)
    {
        cout << tab[1];
        return 0;
    }

    int s = 2*tab[2] + tab[1];

    for (int i = 4; i <= n; i += 2)
    {
        res += s + tab[i];
        //cout << res << ' ';
    }

    if (n%2 == 0)
    {
        cout << res + tab[2];
    }
    else
    {
        cout << res + tab[2] + tab[1] + tab[n];
    }





}