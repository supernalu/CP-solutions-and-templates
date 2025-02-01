#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e4 + 10;
int n, m1, m2;
set<int> adj1[MAXN], adj2[MAXN];
vector<int> odl;
vector<string> res;
void addFirstLayer() {
    queue<int> q;
    odl.assign(n+10, -1);
    q.push(1);
    odl[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        //cout << v << ' ';
        for (auto u : adj1[v]) {
            if (odl[u] != -1)
                continue;
            odl[u] = odl[v]+1;
            if (odl[u] != 1) {
                string tmp = "+ 1 ";
                tmp += to_string(u); 
                res.push_back(tmp);
            }
            q.push(u);
        }
    }
}
void bfs() {
    queue<int> q;
    odl.assign(n+10, -1);
    q.push(1);
    odl[1] = 0;
    stack<string> tmpRes;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        //cout << v << ' ';
        for (auto u : adj2[v]) {
            if (odl[u] != -1)
                continue;
            odl[u] = odl[v]+1;
            if (odl[u] != 1) {
                string tmp = "- 1 ";
                tmp += to_string(u); 
                tmpRes.push(tmp);
            }
            q.push(u);
        }
    }
    while (!tmpRes.empty()) {
        res.push_back(tmpRes.top());
        tmpRes.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m1;
    for (int i = 1; i <= m1; i++) {
        int a, b; cin >> a >> b;
        adj1[a].insert(b);
        adj1[b].insert(a);
    }
    cin >> m2;
    for (int i = 1; i <= m2; i++) {
        int a, b; cin >> a >> b;
        adj2[a].insert(b);
        adj2[b].insert(a);
    }
    addFirstLayer();
    for (int v = 2; v <= n; v++) {
        for (auto u : adj2[v]) {
            if (u < v || adj1[v].find(u) != adj1[v].end())
                continue;
            string tmp = "+ ";
            tmp += to_string(v);
            tmp += ' ';
            tmp += to_string(u);
            res.push_back(tmp);
        }
    }
    for (int v = 2; v <= n; v++) {
        for (auto u : adj1[v]) {
            if (u < v || adj2[v].find(u) != adj2[v].end())
                continue;
            string tmp = "- ";
            tmp += to_string(v);
            tmp += ' ';
            tmp += to_string(u);
            res.push_back(tmp);
        }
    }
    bfs();

    cout << res.size() << '\n';
    for (auto i : res)
        cout << i << '\n';

}