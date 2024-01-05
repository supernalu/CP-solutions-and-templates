#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;

int n, q;

vector<int> adj[MAXN];

tuple<int, int, int> res[110][110][110];

int dist[5010][5010];
int dist2[MAXN];
bool vis[MAXN];

void dfs(int v, int k)
{
    //cout << v << ' ';
    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        vis[u] = 1;
        dist[k][u] = dist[k][v]+1;
        dfs(u, k);
    }
}
void solve1()
{
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            dist2[0] = i;
            int v = i;
            for (int i = 2; i <= n; i++)
            {
                vis[v] = 1;
                for (auto u : adj[v])
                {
                    if (vis[u])
                        continue;
                    dist2[i-1] = u;
                    u = v;
                }
            }
            break;
        }
    }

    while (q--)
    {
        int a, b, c;  cin >> a >> b >> c;

        if (a + b == c )
        {
            cout << "TAK " <<  dist2[0] << ' ' << dist2[a] << ' ' << dist2[a+b];
        }  
        else if (a-b == c)
        {
            cout << "TAK " << dist2[0] << ' ' << dist2[a] << ' ' << dist2[a-b];
        }
        else if (b-a == c)
        {
            cout << "TAK " << dist2[b-a] << dist2[b] << ' ' <<  dist2[0];
        }
        else
            cout << "NIE";
        cout << "\n";
        
    }
}

void solve2()
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 1; dist[i][i] = 0;
        dfs(i, i);
        for (int j = 1; j <= n; j++)
            vis[j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                res[i][j][k] = {-1, -1, -1};
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                res[dist[i][j]][dist[j][k]][dist[k][i]] = {i, j, k};
                //cout << dist[i][j] << dist[j][k] << dist[k][i] << ' ' << i << j << k << '\n';
            }
        }
    }
    while (q--)
    {
        int a, b, c; cin >> a >> b >> c;
        tuple<int,int,int> lol = {-1,-1,-1};

        if (res[a][b][c] == lol)
        {
            cout << "NIE\n";
            continue;
        }
        cout << "TAK " << get<0>(res[a][b][c]) << ' ' << get<1>(res[a][b][c]) << ' ' << get<2>(res[a][b][c]) << '\n';
    }



}

void solve3()
{

}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    int poss = n;

    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b); adj[b].push_back(a);

        if (adj[a].size() == 2)
            poss--;
        if (adj[b].size() == 2)
            poss--;
    }

    if (n <= 100)
    {
        solve2();
        return 0;
    }
    else if (poss == 2)
    {
        solve1();
        return 0;
    }
    else
    {
        solve3();
    }

    



}