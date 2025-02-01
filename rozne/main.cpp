#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define db(x...) cerr << "\e[94m" << "Line: " << __LINE__ << "  " << "\e[91m[" << #x << "] = ["; _print(x); cerr << "\e[39m";
#else
#define db(x...)
#endif

#define ll long long

int solve(int n, int k, int fixed) {
    map<int, int> mp{{1, 2}, {3, 5}};
    db(n, k, fixed, mp);

    int ile;
    if (fixed == 1)
        ile = (n+1)/2;
    else
        ile = n/2;
    if (n == 2 && k == 2 && fixed == 0)
        return 1;
    if (n ==  2 && k == 2 && fixed == 1)
        return 0;
    if (k <= ile && fixed == 1) {
        return 2*k - 1;
    }
    else if (k <= ile && fixed == 0) {
        return 2*k;
    }
    else if (n%2 == 0) {
        return 2*solve(n-ile, k-ile, 1)+(fixed+1)%2;
    }
    else {
        return 2*solve(n-ile, k-ile, 0)+(fixed+1)%2;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        if (n == 1 && k == 1)
            cout << "1\n";
        else
            cout << solve(n, k, 0) << '\n';
    }
}