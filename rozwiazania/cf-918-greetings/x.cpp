#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

constexpr int MAXN = 2e5 + 10;
int t, n;
pair<int, int> range[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> range[i].first >> range[i].second;
        sort(range+1, range+n+1);
        ordered_set s; 
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            res += s.size()-s.order_of_key(range[i].second);
            s.insert(range[i].second);
        }
        cout << res << '\n';   
    }
}