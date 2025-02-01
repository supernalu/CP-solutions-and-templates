#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5+10;
int n, a[MAXN]; 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if (n == 1) {
        cout << -1;
        return 0;
    }
    bool isConstant = 1;
    for (int i = 2; i <= n; i++)
        if (a[i]-a[i-1] != 0)
            isConstant = 0;
    if (isConstant) {
        cout << 1 << '\n';
        cout << a[1];
        return 0;
    }
    if (n == 2) {
        int r = a[2]-a[1];
        vector<int> res;
        if (r%2 == 0)
            res.push_back(a[1]+r/2);
        res.push_back(a[1]-r);
        res.push_back(a[2]+r);
        sort(res.begin(), res.end());
        cout << res.size() << '\n';
        for (auto i : res)
            cout << i << ' ';
        return 0;
    }
    bool isArithmetic = 1;
    for (int i = 2; i < n; i++) {
        if (a[i+1]+a[i-1] != 2*a[i])
            isArithmetic = 0; 
    }
    if (isArithmetic) {
        int r = a[2]-a[1];
        cout << "2\n";
        cout << min(a[1]-r, a[n]+r) << ' ' << max(a[1]-r, a[n]+r);
        return 0;
    }
    int pref = 0, suf = 0;
    int r1 = a[2]-a[1], r2 = a[n]-a[n-1];
    for (int i = 2; i <= n; i++) {
        if (a[i]-a[i-1] != r1) {
            pref = i-1;
            break;
        }
    }
    for (int i = n-1; i > 0; i--) {
        if (a[i+1]-a[i] != r1) {
            suf = i+1;
            break;
        }
    }
    set<int>res;
    //cout << pref << ' ' << suf << '\n';
    if (!(suf-pref > 1 || a[suf]-a[pref] != 2*r1)) {
        res.insert(a[pref]+r1);
    }
    for (int i = 2; i <= n; i++) {
        if (a[i]-a[i-1] != r2) {
            pref = i-1;
            break;
        }
    }
    for (int i = n-1; i > 0; i--) {
        if (a[i+1]-a[i] != r2) {
            suf = i+1;
            break;
        }
    }
    //cout << pref << ' ' << suf << '\n';
    if (!(suf-pref > 1 || a[suf]-a[pref] != 2*r2)) {
        res.insert(a[pref]+r2);
    }
    cout << res.size() << '\n';
    //sort(res.begin(), res.end());
    for (auto i : res)
        cout << i << ' ';
    
}