#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;
constexpr int INF = 1e9 + 10;

int n, m;
int r[MAXN];
int k[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> r[i];    
    for (int i = 1; i <= m; i++)
        cin >> k[i];

    r[0] = INF;
    for (int i = 1; i <= n; i++)
        r[i] = min(r[i], r[i-1]);

    int j = 1;
    for (int i = n; i > 0; i--)
    {
        if (r[i] >= k[j])
        {
            j++;
        }
        if (j > m)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    

}