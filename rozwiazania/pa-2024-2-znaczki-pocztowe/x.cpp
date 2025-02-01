#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5+10;
int n, a[MAXN], res[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int act = 1;
    a[n+1] = 1e9 + 1;
    for (int i = 2; i <= n+1; i++) {
        if (a[i] == a[i-1]) {
            act++;
            continue;
        }
        for (int j = 1; j <= act; j++) {
            res[j] += (act/j)*j;
        }
        act = 1;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
}