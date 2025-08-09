#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
constexpr int MAXN = 5e5 +10;
typedef long long ll;
int t, n, k;
int a[MAXN];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k; 
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        pair<int, int> res;
        int L = 1, R = k;
        ordered_set o_set;
        for (int i = 1; i <= k; i++) {
            o_set.insert({a[i], i});
        }
        res = *(o_set.find_by_order((k/2 + 1)));
        int actL = 1, actR = k+1;
        for (; actR++; actR <=n) {
            pair<int, int> last = *(o_set.find_by_order(o_set.size()/2 +1));
            o_set.insert({a[actR], actR});
            pair<int, int> tmp = *(o_set.find_by_order(o_set.size()/2 +1));
            while (o_set.size() > k && tmp.first < last.first) {
                o_set.erase({a[actL], actL});
                actL++;
                cout << o_set.size() << ' ';
                tmp = *(o_set.find_by_order(o_set.size()/2 +1));
            }
            tmp = *(o_set.find_by_order(o_set.size()/2 +1));
            if (tmp.first > res.first) {
                res = *(o_set.find_by_order(o_set.size()/2 +1));
                L = actL;
                R = actR;
            }
        }
        cout << res.first << ' ' << L << ' ' << R << '\n';
    }
}