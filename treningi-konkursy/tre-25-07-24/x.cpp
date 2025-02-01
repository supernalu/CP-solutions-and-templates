#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t;
long long n, k;
pair<long long, long long> a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        bool b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first == k)
                b = 1;
            if (a[i].second == k)
                c = 1;
        }
        if (b&& c)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}