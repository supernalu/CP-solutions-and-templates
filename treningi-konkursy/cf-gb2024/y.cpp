#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>  
typedef long long ll;
constexpr int MAXN = 3e5+10;
constexpr ll INF = 1e18+10;
constexpr ll MOD = 998244353;
using namespace std;
using namespace __gnu_pbds; 
#define ordered_set tree<pair<ll,int>, null_type,less<pair<ll, int>>, rb_tree_tag,tree_order_statistics_node_update> 
int t;
ll n, q;
ll a[MAXN], b[MAXN], val[MAXN], A[MAXN], B[MAXN];
ll fastExp(ll a, ll b, ll MOD) { 
    if (b == 0)
        return 1;
    ll tmp = fastExp(a, b/2, MOD);
    tmp = (tmp*tmp)%MOD;
    if (b%2)
        return (tmp*a)%MOD;
    return tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q; 
        ordered_set aSorted;
        ordered_set bSorted;
        ll res = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            aSorted.insert({a[i], i});
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            bSorted.insert({b[i], i});
        }
        for (int i = 1; i <= n; i++) {
            ll tmpA = (*(aSorted.find_by_order(i-1))).first, tmpB = (*(bSorted.find_by_order(i-1))).first;
            //cout << tmpA << ' ' << tmpB << '\n';
            val[i] = min(tmpA, tmpB);
            A[i] = tmpA;
            B[i] = tmpB;
            res *= min(tmpA, tmpB);
            res %= MOD;
        }
        cout << res << ' ';
        while (q--) {
            int type, x; cin >> type >> x;
            if (type == 1) {
                    //int oldX = aSorted.order_of_key({a[x], x})+1;
                    int last = aSorted.order_of_key({a[x]+1, 0});
                    aSorted.erase({a[x], x});
                    a[x]++;
                    aSorted.insert({a[x],x});
                    int newX = aSorted.order_of_key({a[x],x})+1;
                    res *= fastExp(val[newX], MOD-2, MOD);
                    res %= MOD;
                    //val[newX] = min(a[x], (*(bSorted.find_by_order(newX-1))).first);
                    val[newX] = min(a[x], B[newX]);
                    A[newX] = a[x];
                    //if (x == 7)
                    //cout << a[x] << ' ' << (*(bSorted.find_by_order(newX-1))).first << ' ' << val[newX]<< '\n';
                    res *= val[newX];
                    res %= MOD;
                    /*
                    if (oldX != newX) {
                        res *= fastExp(val[oldX], MOD-2, MOD);
                        res %= MOD;
                        //val[oldX] = min((*(aSorted.find_by_order(oldX-1))).first, (*(bSorted.find_by_order(oldX-1))).first);
                        A[oldX] = (*(aSorted.find_by_order(oldX-1))).first;
                        val[oldX] = min(A[oldX], B[oldX]);
                        res *= val[oldX];
                        res %= MOD;
                    }
                    */
                    if (last > 0) {
                        res *= fastExp(val[last], MOD-2, MOD);
                        res %= MOD;
                        //val[last] = min((*(aSorted.find_by_order(last-1))).first, (*(bSorted.find_by_order(last-1))).first);
                        A[last] = (*(aSorted.find_by_order(last-1))).first;
                        val[last] = min(A[last], B[last]);
                        res *= val[last];
                        res %= MOD;
                    }
                    



            }
            else {
                //int oldX = bSorted.order_of_key({b[x], x})+1;
                int last = bSorted.order_of_key({b[x]+1, 0});
                bSorted.erase({b[x], x});
                b[x]++;
                bSorted.insert({b[x],x});
                int newX = bSorted.order_of_key({b[x],x})+1;
                res *= fastExp(val[newX], MOD-2, MOD);
                res %= MOD;
                //val[newX] = min(b[x], (*(aSorted.find_by_order(newX-1))).first);
                //val[newX] = min(b[x], val[newX]);
                val[newX] = min(b[x], A[newX]);
                B[newX] = b[x];
                res *= val[newX];
                res %= MOD;
                /*
                if (oldX != newX) {
                    res *= fastExp(val[oldX], MOD-2, MOD);
                    res %= MOD;
                    //val[oldX] = min((*(aSorted.find_by_order(oldX-1))).first, (*(bSorted.find_by_order(oldX-1))).first);
                    B[oldX] = (*(bSorted.find_by_order(oldX-1))).first;
                    val[oldX] = min(A[oldX], B[oldX]);
                    res *= val[oldX];
                    res %= MOD;
                }
                */
                if (last > 0) {
                    res *= fastExp(val[last], MOD-2, MOD);
                    res %= MOD;
                    //val[last] = min((*(aSorted.find_by_order(last-1))).first, (*(bSorted.find_by_order(last-1))).first);
                    B[last] = (*(bSorted.find_by_order(last-1))).first;
                    val[last] = min(A[last], B[last]);
                    res *= val[last];
                    res %= MOD;
                }
            }
            cout << res << ' ';

            //ll check = 1;
            /*
            for (int i = 1; i <= n; i++) {
                cout << val[i] << " (" << (*(aSorted.find_by_order(i-1))).first << ", " << (*(bSorted.find_by_order(i-1))).first << "), ";
                check *= val[i];
                check %= MOD;
            }
            cout << check << '\n';
            */
            
            
        }
        cout << '\n';     
    }
}