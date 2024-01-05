#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9 + 10;
constexpr int MAXN = 1e6 + 10;


int n, m, start, meta;

int k;

bool dang[MAXN];

vector<int> adj[MAXN];

vector<int> dist(MAXN, INF);

pair<int, int> dp[2][MAXN];

pair<int, int> parent[2][MAXN];

void bfs(vector<int> const & a)
{
    queue <int> q;

    for (auto i : a)
    {
        q.push(i);

        dist[i] = 0;
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
        {
            if (dist[u] != INF)
                continue;

            dist[u] = dist[v] + 1;

            q.push(u);
        }
        
    }
}

void solver(int s)
{
    queue<pair<int, int>> q;

    q.push({0, s});

    dp[0][s] = {0, dist[s]};

    while(!q.empty())
    {
        pair<int, int> from = q.front();

        q.pop();

        //cout << from.first << ' ' << from.second << '\n';

        for (auto u : adj[from.second])
        {

            if (dang[u] && from.first)
                continue;


            pair<int, int> to = {dang[u]+from.first, u};

            if (dp[to.first][to.second] == make_pair(INF, INF))
            {
                q.push(to);
            }

            bool isShorter = dp[to.first][to.second].first > dp[from.first][from.second].first + 1;
            bool isEqual = dp[to.first][to.second].first == dp[from.first][from.second].first + 1;
            bool isFurtherFromDangerous = dp[to.first][to.second].second < min(dp[from.first][from.second].second, dist[to.second]);

            if (isShorter || isEqual && isFurtherFromDangerous) {
                dp[to.first][to.second] = make_pair(dp[from.first][from.second].first + 1, min(dp[from.first][from.second].second, dist[to.second]));

                parent[to.first][to.second] = from;
            }

            
            
        }

    }
}


void solve() {
    cin >> n >> m >> start >> meta >> k;

    for (int i = 0; i <= n; ++i) {
        dang[i] = false;
        adj[i].clear();
        dist[i] = INF;
        dp[0][i] = {INF, INF};
        dp[1][i] = {INF, INF};
        parent[0][i] = {0, 0};
        parent[1][i] = {0, 0};
    }
    
    vector<int> dangerous(k);
    for (int i = 0; i < k; ++i) {
        cin >> dangerous[i];
        dang[dangerous[i]] = true;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs(dangerous);


    /*
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << ' ';
    }

    cout << '\n';
    */

    solver(start);

    int result;

    if (dp[0][meta].second == INF && dp[1][meta].second == INF) {
        cout << "NIE\n";
        return;
    }
    else
    {
        cout << "YES ";

        pair<int, int> v;

        v.second = meta;

        if (dp[0][meta].second != INF)
        {
            cout << dp[0][meta].second << '\n' << dp[0][meta].first+1 << ' ';
            result = dp[0][meta].first;
            v.first = 0;
        }
        else
        {
            cout << "0\n" << dp[1][meta].first+1 << ' ';
            result = dp[1][meta].first;
            v.first = 1;
        }

        vector<int> odt;

        
        
        while (result--)
        {
            odt.push_back(parent[v.first][v.second].second);

            v = parent[v.first][v.second];
            //cout << v.first << ' ' << v.second << endl;
        }

        reverse(odt.begin(), odt.end());

        for (auto i : odt)
        {
            cout << i << ' ';
        }
        cout << meta << '\n';
        
    }
    
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}