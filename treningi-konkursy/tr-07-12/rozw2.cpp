#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t, n, B;

vector<int> adj[MAXN];
bool vis[MAXN];
pair<int, int> range[MAXN];
int s[MAXN];

int mini[MAXN], maxi[MAXN];
int res[MAXN];

//1 podzadanie poczatek

void dfs1(int v)
{
    
    mini[v] = range[v].first; maxi[v] = range[v].second;

    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        vis[u] = 1;
        dfs1(u);

        mini[v] = min(mini[v], mini[u]);
        maxi[v] = max(maxi[v], maxi[u]);
    }

    res[v] = max(maxi[v] - range[v].first, range[v].first - mini[v]);

}

int solve1()
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = range[i].first;
        vis[i] = 0;
    }
    
    vis[1] = 1;
    dfs1(1);

    int tmp = 0;

    for (int i = 1; i <= n; i++)
        tmp = max(tmp, res[i]);

    return tmp;
}

//2 podzadanie poczatek

int solve2()
{
    int minii = 1e9 + 10, maxii = -1;

    for (int i = 1; i <= n; i++)
    {
        minii = min(minii, range[i].second);
        maxii = max(maxii, range[i].first);
    }

    for (int i = 1; i <= n; i++)
    {
        if (range[i].second > maxii)
            s[i] = range[i].first;
        else
            s[i] = range[i].second;
    }
    
    return max(maxii-minii, 0);
}

//3 podzadanie poczatek
//!!!NIE DZiALA!!!
void dfs3(int v)
{
    //cout << v << ' ';

    mini[v] = range[v].second; maxi[v] = range[v].first;

    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        vis[u] = 1;
        dfs3(u);

        mini[v] = min(mini[v], mini[u]);
        maxi[v] = max(maxi[v], maxi[u]);
    }

    
    if (range[v].second > maxi[v])
        s[v] = range[v].first;
    else
        s[v] = range[v].second;

    
    res[v] = max(maxi[v]-mini[v], 0);
}

int solve3()
{
    for (int i = 2; i <= n; i++)
        vis[i] = 0;
    vis[1] = 1;
    dfs3(1);

    int tmp = 0;

    for (int i = 1; i <= n; i++)
    {
        if(adj[i].size()==1)
            continue;
        tmp = max(tmp, res[i]);
    }

    return tmp;
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t >> B;

    while (t--)
    {
        cin >> n;

        bool poss = 1;
        bool poss2 = 1;



        for (int i = 1; i <= n; i++)
            adj[i].clear();
        

        for (int i = 2; i <= n; i++)
        {
            int a; cin >> a;
            adj[a].push_back(i);
            adj[i].push_back(a);

            if (a != i-1)
                poss2 = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            int a, b; cin >> a >> b;
            range[i] = {a, b};

            if (a != b)
            {
                poss = 0;
            }
        }

        if(poss)
        {
            cout << solve1() << '\n';
        }
        else if (poss2)
        {
            cout << solve2() << '\n';
        }
        else
        {
            cout << solve3() << '\n';
        }



        if (B == 1)
        {
            for (int i = 1; i <= n; i++)
                cout << s[i] << ' ';
            cout << '\n';
        }
   
    }

}
