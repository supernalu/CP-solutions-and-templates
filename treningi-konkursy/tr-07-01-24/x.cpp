#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, q;
multiset<pair<int, int>> normal, reversed; 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--) {
        char type; int l, r; cin >> type >> l >> r;
        if (type == '+') {
            normal.insert({l , r});
            reversed.insert({r, l});
        }
        else {
            normal.erase(normal.lower_bound({l , r}));
            reversed.erase(reversed.lower_bound({r, l}));  
        }
        if (normal.size() > 1) {
            int bestEnd = (*reversed.begin()).first;
            int bestBegin = (*normal.rbegin()).first;
            if (bestEnd < bestBegin)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
}