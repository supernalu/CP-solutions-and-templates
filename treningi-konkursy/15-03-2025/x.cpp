#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#ifdef DEBUG
template<typename T1, typename T2> auto& operator<<(ostream& o, pair<T1, T2> a) { return o << "(" << a.first << ", " << a.second << ")"; }
template<typename T, typename OS> auto& operator<<(OS& o, T a) { o << "{"; for(auto b : a) o << b << ", "; return o << "}"; }
#define db(x...) cerr << "[" #x "]: ", [](auto... args) { ((cerr << args << ", "),...) << "\n"; }(x)
#else
#define db(...)
#endif

template<class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using vi = vector<int>;

mt19937 mrand(random_device{}());
ll rnd(ll l, ll r) { return l + mrand() % (r - l + 1);}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
    }
}