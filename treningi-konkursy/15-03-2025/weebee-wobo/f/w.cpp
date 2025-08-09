#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#ifdef DEBUG
template<typename T1,typename T2>auto& operator<<(ostream&o,pair<T1,T2>a){return o<<"("<<a.first<<", "<<a.second<<")";}
template<typename T,size_t...I>void pt(ostream&o,T t,index_sequence<I...>){o<<"(";(...,(o<<(I?", ":"")<< get<I>(t)));o<<")";}
template<typename...A>auto& operator<<(ostream&o,tuple<A...>t){pt(o,t,index_sequence_for<A...>{});return o;}
template<typename T,typename O>auto& operator<<(O&o,T a){o<<"{";for(auto b:a)o<<b<<", ";return o<<"}";}
#define db(x...) cerr << "\033[92m" << "[" #x "]: ", [](auto... args) { ((cerr << args << ", "),...) << "\033[0m" << "\n"; }(x)
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
    
}