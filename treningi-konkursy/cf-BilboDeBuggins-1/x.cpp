#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e4+10;
typedef long long ll;
int n, m;
tuple<ll, ll, ll> arr[MAXN];
set<ll> adj[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[i] = {c, a, b};
    }
    sort(arr+1, arr+m+1);
    int ile = 0;
    for (int i = 1; i <= m; i++) {
        //cout << i << ' ' << get<0>(arr[i]) << ' ' << get<1>(arr[i]) << ' ' <<get<2>(arr[i]) << ' ' << ile << '\n';
        adj[get<1>(arr[i])].insert(get<2>(arr[i])+n);
        adj[get<2>(arr[i])+n].insert(get<1>(arr[i]));
        if (adj[get<1>(arr[i])].size() == 1)
            ile++;
        if (adj[get<2>(arr[i])+n].size() == 1)
            ile++;
        if (ile == 2*n && i >= 2*n) {
            cout << get<0>(arr[i]);
            return 0;
        }
    }
    cout << "-1";
}