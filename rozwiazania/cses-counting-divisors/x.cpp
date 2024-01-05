#include <bits/stdc++.h>
#define ll long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
vector<int> exponents[MAXN];
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); getExponents(MAXN, exponents);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        int res = 1;
        for (auto i : exponents[n]) {
            res *= (i+1); 
        }
        cout << res << '\n';
    }
}