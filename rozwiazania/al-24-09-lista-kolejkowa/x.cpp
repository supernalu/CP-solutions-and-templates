#include <bits/stdc++.h>
using namespace std; 
constexpr int MAXN = 250010;
constexpr long double INF = 1 << 30;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<pair<long double, int>, null_type,less<pair<long double, int>>, rb_tree_tag,tree_order_statistics_node_update> 
int n;
ordered_set s;
long double wh[MAXN];
void debug(int k) {
    for (int i = 0; i <= k+1; i++)
        cout << (*s.find_by_order(i)).first << ' ' << (*s.find_by_order(i)).second << ", ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cin >> n;
    int ile = 0;
    s.insert({0, 0});
    s.insert({INF, 0});
    string sss;
    while(getline(cin , sss)) {
        stringstream lol{sss};
        int a, b; lol >> a >> b;
        if (a == 1) {
            long double c = (*s.find_by_order(b-1)).first, d = (*s.find_by_order(b)).first;
            long double tmp = (c+d)/2;
            ile++;
            s.insert({tmp, ile});
            wh[ile] = tmp;
        }
        else if (a == 3) {
            pair<long double, int> tmp = *(s.find_by_order(b));
            cout << tmp.second << '\n';
        }
        else {
            cout << s.order_of_key({wh[b], b}) << '\n';   
        }
    }
} 