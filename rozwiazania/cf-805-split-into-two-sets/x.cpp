#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t, n;

vector<int> wh[MAXN];
vector <int> color(MAXN, 0);
vector <int> adj[MAXN];
bool is_good = true;
 
void dfs(int v, int clr)
{
    color[v] = clr;
    for (auto u: adj[v])
    {
        if (color[u] != 0)
        {
            if (color[u] == clr) 
            {
                is_good = false;
            }
            continue;
        }        
        dfs(u, ((clr) % 2 + 1));
        
    }
}
 



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        
        bool res = 1;
        is_good = 1;

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            wh[i].clear();
            color[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            int a, b;

            cin >> a >> b;

            wh[b].push_back(i);
            wh[a].push_back(i);

            if (a == b)
                res = 0;
        }


        for (int i = 1; i <= n; i++)
        {
            if (wh[i].size() > 2)
            {
                res = 0;

                break;
            }

            if (wh[i].size() == 2)
            {
                adj[wh[i][0]].push_back(wh[i][1]);
                adj[wh[i][1]].push_back(wh[i][0]);
            }
        }

        if (!res)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                color[i] = 1;            
                dfs(i, 1);
                //cout << endl;
            }
        }

        if (is_good)
            cout << "YES\n";
        else 
            cout << "NO\n"; 
        
        



    }
}