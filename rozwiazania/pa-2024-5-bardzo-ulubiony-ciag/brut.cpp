#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 510;
int n;
ll a[MAXN];
ll pref[MAXN];
vector<ll> b;
map<ll, ll> m;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    cin >> n;
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            b.push_back(pref[i]-pref[j]);
            m[pref[i]-pref[j]] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            m[pref[i]-pref[j]]++;
        }
    }

}