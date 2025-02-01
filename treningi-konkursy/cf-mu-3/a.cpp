#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 1e5 + 10;
int n, m;
int a[12][MAXN];
int wh[12][MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            wh[i][a[i][j]] = j;
        }
    }
    int act[12];
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int j = i+1;
        for (int k = 1; k <= m; k++)
            act[k] = wh[k][a[1][i]];
        for (; j <= n; j++) {
            bool canProcced = 1;
            for (int k = 1; k <= m; k++) {
                act[k]++;
                if (act[k] > n)
                    canProcced = 0;
            }
            
            for (int k = 2; k <= m; k++) {
                if (a[k][act[k]] != a[1][j])
                    canProcced = 0;
            }
            if (!canProcced) 
                break;
        }
        //cout << j << ' ';
        ll ii = i;
        ll jj = j;
        res += (jj-ii+1)*(jj-ii)/2;
        i = j-1;
    }
    cout << res;
}