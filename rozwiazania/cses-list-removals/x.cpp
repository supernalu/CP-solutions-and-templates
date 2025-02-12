#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

constexpr int MAXN = 2e5 + 10;
int n, a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    ordered_set s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        int q; cin >> q;
        int tmp = *(s.find_by_order(q-1));
        cout << a[tmp] << ' ';
        s.erase(tmp);
    }
}