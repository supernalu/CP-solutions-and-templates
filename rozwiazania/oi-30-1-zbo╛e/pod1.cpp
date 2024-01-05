#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, k;

vector<pair<int, long long>> adj[MAXN];
long long dist[MAXN];

namespace subtask1 {

    void initiation(int v)
    {
        for (int i = 1; i <= n; i++)
        {
            dist[i] = -1;
        }
        dist[v] = 0;
    }

    void dfs(int v)
    {
        for (auto u : adj[v])
        {
            if (dist[u.first] != -1)
                continue;

            dist[u.first] = dist[v] + u.second;
            dfs(u.first);
        }
    }

    void solve()
    {
        vector<int> castles = {1};

        long long res = 0;

        while(k--)
        {
            
            int a;
            cin >> a;

            initiation(a);
            dfs(a);

            

            for (auto i : castles)
                res += dist[i]*2;

            cout << res << '\n';

            castles.push_back(a);
        }
    }

}   

namespace subtask2 {

    

    void solve()
    {


        while(k--)
        {

        }
    }

}



void readInput()
{
    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
}

bool sciezka()
{
    for (int i = 2; i < n; ++i) {
        if (adj[i].size() != 2) {
            return false;
        }
        if (adj[i][0].first != i - 1 && adj[i][1].first != i + 1 || adj[i][0].first != i + 1 && adj[i][1].first != i - 1) {
            return false;
        }
    }
    if (adj[1].size() != 1 || adj[1][0].first != 2) {
        return false;
    }
    if (adj[n].size() != 1 || adj[n][0].first != n - 1) {
        return false;
    }
    return true;
}

void solve()
{
    if (n * k <= 100000) {
        subtask1::solve();
    }
    else if (sciezka()) {
        //subtask2();
    }
    else {
        //subtask3();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    readInput();
    solve();
}