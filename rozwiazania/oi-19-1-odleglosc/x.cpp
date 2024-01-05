#include <bits/stdc++.h>


#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }









#define ll long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n, a[MAXN], res[MAXN], odl[MAXN], resOdl[MAXN];
vector<int> expp[MAXN];
vector<vector<int>> isThere(MAXN);
void getExponents(const int maxi, vector<int>tab[]) {
    tab[1].push_back(0);
    bool done[maxi+1];
    for (int i = 1; i <= maxi; i++) done[i] = 0;
    for (int i = 2; i <= maxi; i++)
    {
        if (done[i]) continue;
        tab[i].push_back(1); done[i] = 1;
        for (int j = 2*i; j <= maxi; j += i) {
            int tmp = j, res = 0;
            done[j] = 1;
            while (tmp%i == 0) {
                res++; tmp /= i;
            }
            tab[j].push_back(res);
        }
    }
}
void solve(int GCD) {
    vector<pair<int, int>> tmp;
    for (int i = GCD; i < MAXN; i+=GCD) {
        for (auto j : isThere[i])
            tmp.push_back({odl[i]-odl[GCD], j});
    }
    sort(tmp.begin(), tmp.end());
    int nn = tmp.size();
    if (nn > 0)
    //cout << tmp[0].first << ' ' << tmp[0].second << ", ";
    for (int i = 1; i < nn; i++) {
        //cout << tmp[i].first << ' ' << tmp[i].second << ' ' << resOdl[tmp[i].second] << ", ";
        int tmpOdl = tmp[0].first+tmp[i].first;
        if (tmpOdl < resOdl[tmp[i].second] || (tmpOdl < resOdl[tmp[i].second] && tmp[0].second < res[tmp[i].second])) {
            //cout << "trololo";
            res[tmp[i].second] = tmp[0].second;
            resOdl[tmp[i].second] = tmpOdl;
        }
    }
    if (nn >= 2) {
        int tmpOdl = tmp[0].first+tmp[1].first;
        if (tmpOdl < resOdl[tmp[0].second] || (tmpOdl < resOdl[tmp[0].second] && tmp[1].second < res[tmp[0].second])) {
            //cout << "trololo";
            res[tmp[0].second] = tmp[1].second;
            resOdl[tmp[0].second] = tmpOdl;
        }
    }
    //if (nn != 0)
    //cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    
    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            resOdl[i] = 1e9+7;
            cin >> a[i];
            isThere[a[i]].push_back(i);
            maxi = max(maxi, a[i]);
        }
        /*
        for (int i = 1; i <= maxi; i++) {
            if (isThere[i] > 1) {
                resO
            }
        }
        */
        
        getExponents(maxi, expp);
        for (int i = 1; i <= maxi; i++)
            for (auto j : expp[i])
                odl[i] += j;
        for (int i = 1; i <= maxi; i++) 
            solve(i);
        for (int i = 1; i <= n; i++)
            cout << res[i] << '\n';
    }
}