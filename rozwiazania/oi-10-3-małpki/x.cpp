#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n, m;
int l[MAXN], r[MAXN];
int when[MAXN];
void dfs(int v, int moment) {
    if (when[v] != -1)
        return;
    when[v] = moment;
    if (l[v] != -1)
        dfs(l[v], moment); 
    if (r[v] != -1)   
        dfs(r[v], moment);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int maxi = n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        maxi = max({maxi, l[i], r[i]});
    }
    for (int i = 1; i <= maxi; i++)
        when[i] = -1;
    for (int i = 1; i <= m; i++) {
        int q1, q2; cin >> q1 >> q1;
        if (q2 == 1) {
            dfs(l[q1], i-1);
            l[q1] = -1;
        }
        else {
            dfs(r[q1], i-1);
            r[q1] = -1;  
        }
    } 
    
    for (int i = 1; i <= n; i++)
        cout << when[i] << '\n';
}