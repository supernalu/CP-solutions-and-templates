#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n;
pair<long long, long long> interval[MAXN];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    long long rA = a.second-a.first, rB = b.second-b.first;
    if (rA == rB)
        return a.first < b.first;
    return rA < rB;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> interval[i].first >> interval[i].second;
        }
        sort(interval+1, interval+n+1, cmp);
    }
}