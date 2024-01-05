
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n, m, q, ancestor[MAXN][30], depth[MAXN];
vector<int> adj[MAXN];
vector<int> objects[MAXN][30];

void getTree() {
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
vector<int> combine(vector<int>a, vector<int> b, int c) {
    //cout << "done";
    int i = 0, j = 0, k = c;
    vector<int> tmp;
    while (k--) {
        //cout << "done";
        if (i >= a.size() && j >= b.size())
            break;
        else if (j >= b.size()) {
            tmp.push_back(a[i]);
            i++;
        }
        else if (i >= a.size()) {
            tmp.push_back(b[j]);
            j++;
        }
        else if (a[i] < b[j]) {
            tmp.push_back(a[i]);
            i++;
        }
        else {
            tmp.push_back(b[j]);
            j++;
        }
    }
    return tmp;
}
void firstLayer(int v) {
    for (auto u : adj[v]) {
        if (ancestor[v][0] == u)
            continue;
        depth[u] = depth[v]+1;
        ancestor[u][0] = v;
        firstLayer(u);
    }
}
void Rootify(int root) {
    depth[root] = 1;
    firstLayer(root);
    for (int pow = 1; pow < 30; pow++) {
        for (int i = 1; i <= n; i++) {
            ancestor[i][pow] = ancestor[ancestor[i][pow-1]][pow-1];
            objects[i][pow] = combine(objects[i][pow-1], objects[ancestor[i][pow-1]][pow-1], 10);         
        }
    }
}
vector<int> lca(int a, int b, int c) {
    if (depth[a] < depth[b])
        swap(a, b);
    int tmp = depth[a]-depth[b];
    vector<int> res;
    for (int i = 29; i >= 0; i--)
        if (tmp >= (1 << i)) {
            tmp -= (1 << i);
            res = combine(res, objects[a][i], c);
            a = ancestor[a][i];
        }
    if (a == b) {
        res = combine(res, objects[a][0], c);
        return res;
    }
    for (int i = 29; i >= 0; i--)
        if (ancestor[a][i] != ancestor[b][i]) {
            res = combine(res, objects[a][i], c); res = combine(res, objects[b][i], c);
            a = ancestor[a][i]; b = ancestor[b][i];
        }
    res = combine(res, objects[a][1], c);
    res = combine(res, objects[b][0], c);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    getTree();
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        if (objects[a][0].size() < 10)
            objects[a][0].push_back(i);
    } Rootify(1);
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        vector<int> tmp = lca(a, b, c);
        cout << tmp.size() << ' ';
        for (auto u : tmp)
            cout << u << ' ';
        cout << '\n';
    }

}