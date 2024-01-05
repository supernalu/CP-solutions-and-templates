#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 30;

int n, m;
vector<int> adj[MAXN];
vector<int> prevPerm(MAXN, 0);
vector<int>res;

int solve(int a, int k)
{
    prevPerm[a-1] = 1;

    if (k == n/2)
    {
        int tmp = 0;

        for (int i = 1; i <= n; i++)
        {
            for (auto u : adj[i])
            {
                if (prevPerm[u-1] != prevPerm[i-1])
                    tmp++;
            }    
        }
        return tmp;
    }
    int t = 1e9;
    for (int i = a+1; i <= (n/2)+k+1; i++)
    {
        t = min(t, solve(i, k+1));
    }

    prevPerm[a-1] = 0;
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    cout << solve(0, 0);

   
}