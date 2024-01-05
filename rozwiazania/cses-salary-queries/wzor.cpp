#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set_pair tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
constexpr int MAXN = 2e5 + 10;
int n, q, x[MAXN];
ordered_set_pair s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        s.insert({x[i], i});
    }
    while (q--) {
        char a; int b, c; cin >> a >> b >> c;
        if (a == '!') {
            s.erase({x[b], b});
            x[b] = c;
            s.insert({x[b], b});
        }
        else {
            int mini = s.order_of_key({b, 0}), maxi = s.order_of_key({c, MAXN});
            cout << maxi-mini << '\n';
        }
    }
}