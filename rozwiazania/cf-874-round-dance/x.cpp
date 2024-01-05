#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n;
int adj[MAXN];
bool vis[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> adj[i];
            vis[i] = 0;
        }

        int mini = 1;
        int maxi = 0;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            int size = 0;
            maxi++;
            int j = i;
            while (vis[j] != 1)
            {
                vis[j] = 1; 
                j = adj[j];
                size++;
            }

            if (j == i && size != 2)
                mini++;
        }
        cout << mini << ' ' << maxi << '\n';


    }
}