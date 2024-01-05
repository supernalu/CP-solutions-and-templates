//INF279994
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
constexpr int MAXN = 1e5 + 10;
constexpr int MOD = 1e8;

int n, m;
vector<int>adj[MAXN];
vector<int> topo;
vector<bool>vis(MAXN, 0);
long long dp[MAXN];

void dfs(int v)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        dfs(u);
    }
    topo.push_back(v);
}

int main()
{
    ifstream plik;
    ofstream wyj;
    plik.open("nar.in");
    wyj.open("nar.out");

    while(true)
    { 
        plik >> n >> m;
        if (n == m && n == 0)
            return 0;

        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            dp[i] = 0;
            adj[i].clear();
        }
        topo.clear();


        for (int i = 1; i <= m; i++)
        {
            int a, b; plik >> a >> b;

            adj[a].push_back(b);
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            dfs(i);
        }
        reverse(topo.begin(), topo.end());

        for (int i = 1; i <= n; i++)
            vis[i] = 0;

        bool res2 = 1;
        bool res = 1;
        dp[1] = 1;
        for (auto i : topo)
        {
            if (i == 1 && vis[2])
                res2 = 0;
                
            for (auto u : adj[i])
            {
                dp[u] += dp[i];
                dp[u] %= MOD;
                if (vis[u] == 1)
                {
                    res = 0;
                    break;
                }
            }
            vis[i] = 1;
        }
        if (res2 == 0)
            wyj << "0\n";
        else if (res == 0)
            wyj << "-1\n";  
        else
            wyj << dp[2] << '\n';
    } 
    wyj.close();
    plik.close();
}