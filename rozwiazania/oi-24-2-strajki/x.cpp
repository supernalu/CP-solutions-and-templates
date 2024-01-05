#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int n, q;

vector<int>adj[MAXN];

int neighoburs[MAXN];

vector<bool> used(MAXN, 1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n-1; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);

        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        neighoburs[i] = adj[i].size();
    }

    cin >> q;


    int res = 1;

    while(q--)
    {
        int a;

        cin >> a;

        if (a > 0)
        {
            used[a] = 0;

            res += neighoburs[a] - 1;

            for (auto u : adj[a])
            {   
                neighoburs[u]--;           
            }


        }
        else
        {
            a = abs(a);

            used[a] = 1;

            res -= neighoburs[a] - 1;

            for (auto u : adj[a])
            {
                neighoburs[u]++;
                
            }
        }

        cout << res << '\n';
    }


}