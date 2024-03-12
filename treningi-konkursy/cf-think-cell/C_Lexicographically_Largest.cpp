#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/
constexpr int MAXN = 3e5 + 10;
constexpr int INF = 1e9 + MAXN + 30;
typedef long long ll;
int t, n;
int a[MAXN];
int id[MAXN];
multiset<pair<int, int>> range;
bool cmp (int b, int c) {
    if (a[b] + b == a[c] + c)
        return b < c;
    return a[b]+b > a[c]+c;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        range.clear();
        //ordered_set used;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            range.insert({a[i]+i, a[i]+1});
        }
        for (auto i = range.begin(); i != range.end(); i++)
            cout << (*i).first << ' ' << (*i).second << "| ";
        int last = INF;
        for (int i = 1; i <= n; i++) {
            auto tmp = range.lower_bound({last, last});
            //cout << (*tmp).first << ' ' << (*tmp).second << ' ';
            if (tmp == range.begin())
                continue;
            tmp--;
            auto act = *tmp;
            cout << act.first << ' ' << act.second << '\n';
            int res = min(last-1, act.first);
            cout << res << ' ';
            last = res;
            range.erase(tmp);
        }
        cout << '\n';

    }
}