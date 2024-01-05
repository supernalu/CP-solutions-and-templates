#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 5e5;


int n;
int a[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];
int subtreeSize[MAXN];

void countSize(int v)
{
    for (auto u : adj[v])
    {
        if (parent[u] == v)
            continue;
        parent[u] = v;
        countSize(u);
        subtreeSize[v] += subtreeSize[u];
    }
    subtreeSize[v]++;
}


void dfs(int v)
{
    for (auto u : adj[v])
    {
        if (parent[u] == v)
            continue;

        
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    int st = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (a[i] > a[st])
            st = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    countSize(st);


    
}