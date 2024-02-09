#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n, k;
int d[MAXN];
multiset<int> l;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= k; i++) {
        int tmp; cin >> tmp; 
        l.insert(tmp);
    }
    sort(d+1, d+n+1); 
    int res = 0;
    for (int i = n; i > 0; i--) {
        auto it = l.lower_bound(5*d[i]);
        if (it != l.end()) {
            res += 1;
            l.erase(it);
            continue;
        }
        res+=2;
        auto it2 = l.lower_bound(3*d[i]);
        if (it2 == l.end()) {   
            res = -1;
            break;
        }
        l.erase(it2);
        auto it3 = l.lower_bound(2*d[i]);
        if (it3 == l.end()) { 
            res = -1;
            break;
        }
        l.erase(it3);
    }
    if (res == -1)
        cout << "NIE";
    else
        cout << res;
    
}