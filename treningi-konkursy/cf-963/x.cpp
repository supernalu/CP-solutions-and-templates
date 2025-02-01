#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 5e5 + 10;
constexpr ll INF = 1e18+10;
int t, n, k;
ll a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        pair<ll, ll> range = {a[n], a[n]+k-1};
        bool poss = 1;
        for (int i = 1; i < n; i++) {
            ll tmp = a[n]+k-1-a[i];
            tmp /= k;
            ll newEnd = a[i]+tmp*k;
            if (tmp%2 == 0) {
                range.first = max(range.first, newEnd);
            }
            else {
                range.second = min(range.second, newEnd-1);
            }

            if (range.first>range.second) {
                poss = 0;
                break;
            }
        }
        if (!poss) {
            cout << "-1\n";
        }
        else {
            cout << range.first << '\n';
        }

    }
}