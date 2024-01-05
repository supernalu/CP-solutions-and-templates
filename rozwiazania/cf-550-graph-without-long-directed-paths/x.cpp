#include<bits/stdc++.h>
 
using namespace std;
 
constexpr int MAXN = 200005;
 
int n, m;
 
vector <int> color(MAXN, 0);
vector <int> adj[MAXN];
bool is_good = true;
 
void dfs(int v, int clr)
{
    //cout << v << ' ' << clr << '\n';

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
 
pair<int, int> c[MAXN];

int main()
{
    cin >> n >> m;
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        c[i] = {a,b};
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;  
            //cout << '\n';          
            dfs(i, 1);
        }
    }
 
    if (is_good)
    {
        cout << "YES\n";

        for (int i = 0; i < m; i++)
        {
            //cout << c[i].first << ' ';

            
            if (color[c[i].first] == 1)
                cout << '1';
            else
                cout << '0';
            
        }
    }
    else 
    {
       cout << "NO"; 
    }
 
}