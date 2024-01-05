#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 5e5 + 10;

int n, m;
int nSkl;

vector<int> adj[MAXN], revAdj[MAXN];
set<int> sklAdj[MAXN], revSklAdj[MAXN];
int dp[MAXN], revDp[MAXN];

vector<bool> vis(MAXN, 0);
vector<int> skl[MAXN];
int vertexSkl[MAXN];
vector<int> topoPrime;

void firstDfs(int v)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        firstDfs(u);
    }
    topoPrime.push_back(v);
}

void revDfs(int v)
{
    vis[v] = 1;

    for (auto u : revAdj[v])
    {
        if (vis[u])
            continue;
        revDfs(u);
    }
    skl[nSkl].push_back(v);
    vertexSkl[v] = nSkl;
}

void db() {
    cout << "Wierzcholek: silnie spojna skladowa\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << vertexSkl[i] << '\n';
    }
    cout << "\nGraf silnie spojnych (dni parzyste):\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto x : sklAdj[i]) {
            cout << x << ' ';
        } cout << '\n';
    }
    cout << "\nGraf silnie spojnych (dni nieparzyste):\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto x : revSklAdj[i]) {
            cout << x << ' ';
        } cout << '\n';
    }
    cout << "\nSilnie spojna: DP, revDP\n";
    for (int i = 1; i <= nSkl; ++i) {
        cout << i << ": " << dp[i] << ", " << revDp[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> n >> m;

    while (m--)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b); 
        revAdj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        firstDfs(i);
    }
    reverse(topoPrime.begin(), topoPrime.end());

    vis.assign(MAXN, 0);

    for (auto v : topoPrime)
    {
        if (vis[v])
            continue;
        nSkl++;
        revDfs(v);
    }

    for (int v = 1; v <= n; v++)
    {
        for (auto u : adj[v])
        {
            if (vertexSkl[v] != vertexSkl[u])
            {
                sklAdj[vertexSkl[v]].insert(vertexSkl[u]);
                revSklAdj[vertexSkl[u]].insert(vertexSkl[v]);
            }
        }
    }
    
    for (int v = 1; v <= nSkl; v++)
    {
        if (sklAdj[v].empty())
        {
            dp[v+1]++;
            continue;
        }
        int u = *(sklAdj[v].begin());
        
        dp[v+1]++;
        dp[u]--;
    }
    dp[0] = 0;
    for (int i = 1; i <= nSkl; i++)
    {
        dp[i] += dp[i - 1];   
    }

    for (int v = nSkl; v > 0; v--)
    {
        if (revSklAdj[v].empty())
        {
            revDp[v-1]++;
            continue;
        }
        int u = *(revSklAdj[v].rbegin());
        
        revDp[v-1]++;
        revDp[u]--;
    }
    revDp[nSkl+1] = 0;
    for (int i = nSkl; i > 0; i--)
    {
        revDp[i] += revDp[i + 1];   
    }

    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        int v = vertexSkl[i];

        if (dp[v] == 0 && revDp[v] == 0)
            res.push_back(i);
    }
    cout << res.size() << '\n';

    for (auto i : res)
        cout << i << ' ';

      
    //db();
}