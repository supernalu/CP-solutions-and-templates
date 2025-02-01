#include <bits/stdc++.h>
using namespace std;
int n;
int a[20][20][20];
bool column[20], file[20];
int res = 1e9 + 7;
int act = 0;
void solve(int k) {
    if (k == n) {
        res = min(res, act);
        return;
    }
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
            }
        }
    }
}