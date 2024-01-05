#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, k;
string a[MAXN];
string mask (int a, int k) {
    string res = "";
    for (int i = k-1; i >= 0 ; i--) {
        if (a >= (1 << i)) {
            res.push_back('1');
            a -= (1 << i);  
        }
        else
            res.push_back('0');
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp; string[i]
        }
    }
}