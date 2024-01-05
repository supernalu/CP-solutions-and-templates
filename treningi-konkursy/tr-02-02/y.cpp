#include<bits/stdc++.h>

using namespace std;
constexpr int MAXN = 270;

int n, m, k;
vector<int> adj[MAXN];
set<int> traveler[MAXN][MAXN];
int tr[MAXN];
int odl[MAXN][MAXN];

void bfs(int st)
{
    queue<int> q;
    q.push(st); odl[st][st] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto u : adj[v])
        {
            if (odl[st][u] != 1e9 + 10)
                continue;
            odl[st][u] = odl[st][v]+1;
            q.push(u);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++)
    {
        int a; cin >> a;
        traveler[i][0].insert(a);
        tr[i] = a;
    }
    while (m--)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    if (n <= 10)
    {
    for (int i = 0; i < MAXN; i++)
    {
        for (int v = 1; v <= n; v++)
        {
            bool poss = 1;
            for (int u = 1; u <= k; u++)
            {
                if (traveler[u][i].find(v) != traveler[u][i].end())
                    continue;
                poss = 0;
                break;
            }
            if (poss)
            {
                cout << "TAK\n";
                cout << i;
                return 0;
            }   
        }

        for (int v = 1; v <= k; v++)
        {
            for (auto u: traveler[v][i])
            {
                for (auto h : adj[u])
                    traveler[v][i+1].insert(h);
            }
        }
        
    }
    cout << "NIE\n";
    return 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            odl[i][j] = 1e9 + 10;
        }

    for (int i = 1; i <= k; i++)
        bfs(tr[i]);

    /*
    for (int i =1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (odl[i][j] == 1e9+10)
            {
                cout << -1 << ' ';
                continue;
            }
            cout << odl[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    int res = 1e9 + 10;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j  <= k; j++)
            tmp = max(tmp, odl[tr[j]][i]);
        res = min(tmp, res);  
    }
    if (res == 1e9 + 10)
        cout << "NIE";
    else
        cout << "TAK\n" << res;

    


}