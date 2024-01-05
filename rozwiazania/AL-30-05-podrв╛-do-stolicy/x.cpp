#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n, ancestor[MAXN][30], depth[MAXN];
vector<int> adj[MAXN];
void getTree()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
void firstLayer(int v)
{
    for (auto u : adj[v])
    {
        if (ancestor[v][0] == u)
            continue;
        depth[u] = depth[v]+1;
        ancestor[u][0] = v;
        firstLayer(u);
    }
}
void Rootify(int root)
{
    depth[root] = 1;
    firstLayer(root);
    for (int pow = 1; pow < 30; pow++) {
        for (int i = 1; i <= n; i++)
            ancestor[i][pow] = ancestor[ancestor[i][pow-1]][pow-1];
    }
}
int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int tmp = depth[a]-depth[b];
    for (int i = 29; i >= 0; i--)
        if (tmp >= (1 << i)) {
            tmp -= (1 << i);
            a = ancestor[a][i];
        }
    if (a == b)
        return a;
    for (int i = 29; i >= 0; i--)
        if (ancestor[a][i] != ancestor[b][i]) {
            a = ancestor[a][i]; b = ancestor[b][i];
        }
    return ancestor[a][0];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getTree();
    Rootify(1);
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}