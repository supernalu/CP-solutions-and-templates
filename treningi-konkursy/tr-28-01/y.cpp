#include<bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e6+10;

int n, k;
set<int> adj[MAXN];
set<int> leaves;

void initiation()
{
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
            leaves.insert(i);   
    }
}

void eraseLeaves()
{
    set<int> tmp;
    
    for (auto v : leaves)
    {
        set<int>tmp2 = adj[v];
        for (auto u : tmp2)
        {
            if (adj[u].size()-1 < 2)
                tmp.insert(u);
            adj[v].erase(u);
            adj[u].erase(v);
        }
        adj[v] = tmp2;
    }
    leaves.clear();
    leaves = tmp;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);
    }
    initiation();

    int res = 0;

    while (leaves.size() > k)
    {
        eraseLeaves();
        res++;
    }

    cout << res << ' ' << max(2, (int)leaves.size()) << '\n';
    

    for (auto i : leaves)
        cout << i << ' ';

    if (leaves.size() == 1)
        cout << (*(leaves.begin())+1)%n+1;
}