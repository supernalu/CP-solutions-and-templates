#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e3 + 10;

int n, q;

char x[MAXN];

int pref[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> x+1;

        for (int j = 1; j <= n; j++)
        {
            if (x[j] == '*')
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + 1;
            else
                 pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];

            //cout << pref[i][j] << ' ';
        }

        //cout << '\n';
    }



    while (q--)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        cout << pref[c][d] + pref[a-1][b-1] - pref[a-1][d] - pref[c][b-1] << '\n';
    }
}