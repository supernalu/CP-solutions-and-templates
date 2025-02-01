#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 7010;
constexpr ll INF = 1e18 + 10;
int n, k, m;
vector<pair <ll, ll>> a[MAXN];
ll dpCostRow[MAXN][MAXN];
ll dpCostWhole[MAXN][MAXN];
ll res[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        ll type, mass, price; cin >> type >> mass >> price;
        a[type].push_back({mass, price});
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < m; j++)
            dpCostRow[i][j] = INF;
    }
    dpCostRow[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (auto u : a[i+1]) {
            ll mass = u.first, cost = u.second;
            for (int j = 0; j < m; j++) {
                if (dpCostRow[i][j] == INF)
                    continue;
                dpCostRow[i+1][(j+mass)%m] = min(dpCostRow[i+1][(j+mass)%m], dpCostRow[i][j]+cost);
            }
        }
    }
    /*
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < m; j++) {
            cout << dpCostRow[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            dpCostWhole[i][j] = INF;
    }
    dpCostWhole[0][0] = 0;
    for (int i = 0; i < m-1; i++) { 
        for (ll mass = 0; mass < m; mass++) {
            if (dpCostRow[n][mass] == INF)
                continue;
            for (int j = 0; j < m; j++) {
                if (dpCostWhole[i][j] == INF)
                    continue;
                dpCostWhole[i+1][(j+mass)%m] = min(dpCostWhole[i+1][(j+mass)%m], dpCostWhole[i][j]+dpCostRow[k][mass]);
            }  
        }
    }
    /*
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << dpCostWhole[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    for (int i = 0; i < m; i++)
        res[i] = INF;
    for (int i = 0; i < m; i++) {   
        for (int j = 0; j < m; j++) {
            res[j] = min(res[j], dpCostWhole[i][j]);
        }  
    }
    for (int i = 0; i < m; i++) {
        if (res[i] == INF)
            cout << -1 << '\n';
        else
            cout << res[i] << '\n';
    }
}

