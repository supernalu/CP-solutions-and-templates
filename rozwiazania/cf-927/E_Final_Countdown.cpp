#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 4e5 + 10;
typedef long long ll;
int t, n;
char s[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s+1;
        vector<int>res;
        ll pref = 0;
        for (int i = 1; i <= n; i++) {
            pref += (ll)(s[i]-'0');
        } 
        ll act = 0;
        for (int i = n; i > 0; i--) {
            act += pref;
            res.push_back(act%10);
            act /= 10;
            pref -= (ll)(s[i]-'0');
        }
        while (act != 0) {
            res.push_back(act%10);
            act /= 10;
        }
        for (int i = res.size()-1; i > 0; i--) {
            if (res[i] != 0)
                break;
            else
                res.pop_back();
        }
        reverse(res.begin(), res.end());
        for (auto i : res)
            cout << i;
        cout << '\n';
    }
}