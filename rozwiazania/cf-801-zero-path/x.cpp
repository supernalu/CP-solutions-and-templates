#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[1010][1010], mini[1010][1010], maxi[1010][1010]; 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                mini[i][j] = 1e9+10;
                maxi[i][j] = -1e9-10;
            }
        mini[1][1] = a[1][1];
        maxi[1][1] = a[1][1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                mini[i+1][j] = min(mini[i+1][j], mini[i][j] + a[i+1][j]);
                mini[i][j+1] = min(mini[i][j+1], mini[i][j] + a[i][j+1]);
                maxi[i+1][j] = max(maxi[i+1][j], maxi[i][j] + a[i+1][j]);
                maxi[i][j+1] = max(maxi[i][j+1], maxi[i][j] + a[i][j+1]);         
            }
        }
        if(mini[n][m] <= 0 && 0 <= maxi[n][m] && mini[n][m]%2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}