#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 36;
constexpr int MAXM = 1010;
int n, m;
pair<int, int> changes[MAXM];
int res[MAXN];
ll power[MAXN];
pair<int, int> solve(ll stPos) {
    ll copy = stPos;
    bool position[MAXN];
    int k = 0;
    for (int i = n-1; i >= 0; i--) {
        if (stPos >= power[i]) {
            k++;
            position[i] = 1;
            stPos -= power[i];
        }
        else
            position[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        if (position[changes[i].first-1] == 1 && position[changes[i].second-1] == 0) {
            swap(position[changes[i].first-1], position[changes[i].second-1]);
        }
        
    }
    int first, last;
    for (int i = 0; i < n; i++) {
        if (position[i] == 1) {
            first = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (position[i] == 1) {
            last = i;
            break;
        }
    }
    if (last-first+1 == k) {
        //cout << copy << '\n';
        return {k, 1};
    }
    else
        return {k, 0};
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    power[0] = 1;
    for (int i = 1; i <= n; i++)
        power[i] = power[i-1]*2;
    for (int i = 1; i <= m; i++) {
        cin >> changes[i].first >> changes[i].second;
    }
    for (int i = 1; i < power[n]; i++) {
        pair<int, int> tmp = solve(i);
        res[tmp.first] = (res[tmp.first]+tmp.second)%2; 
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
}