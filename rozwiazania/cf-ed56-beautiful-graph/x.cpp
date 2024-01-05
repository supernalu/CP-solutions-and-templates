#include<bits/stdc++.h>
 
using namespace std;
 
constexpr int MAXN = 300005;
constexpr long long MOD = 998244353;
 
int n, m;
 
vector <int> color(MAXN, 0);
int il[3];
vector <int> adj[MAXN];
bool is_good = true;

long long res = 0;

void dfs(int v, int clr)
{
    color[v] = clr;
    il[clr]++;
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

    int t;

    cin >> t;

    while(t--)
    {
    is_good = 1;
    res = 1;
    il[1] = 0; il[2] = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        color[i] = 0;

        adj[i].clear();
    }


 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;            
            dfs(i, 1);
            //cout << endl;

            long long tmp = 0;

            for (int i = 1; i <= 2; i++)
            {
                long long tmp2 = 1;

                for (int j = 1; j <= il[i]; j++)
                {
                    tmp2 *= 2;

                    tmp2 %= MOD;
                }

                tmp += tmp2;

                tmp %= MOD;
            }

            res *= tmp;

            res %= MOD;

            il[1] = 0; il[2] = 0;
        }
    }
 
    if (is_good)
    {
        cout << res << '\n';
    }
    else 
    {
       cout << "0\n"; 
    }
    }
 
}

