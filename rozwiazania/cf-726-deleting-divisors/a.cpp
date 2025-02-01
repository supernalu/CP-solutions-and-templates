#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 510;
typedef long long ll;
int n, m; 
ll a[510], b[510];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    bool poss = 1;
    int i = 1;
    vector<string> res;
    for (int act = 1; act <= m; act++) {
        ll sum = 0;
        int L = i;
        vector<ll> tmp;
        while (sum < b[act] && i <= n){
            sum += a[i];
            tmp.push_back(a[i]);
            i++;
 
        }
        int R = i-1;
        if (sum != b[act]) {
            poss = 0;
            break;
        }
        if (L == R)
            continue;
        poss = 0;
        for (int j = L; j < R; j++) {
            if (a[j] != a[j+1])
                poss = 1;
        }
        if (!poss)
            break;
        while (tmp.size() > 1) {
            //cout << tmp.size() << '\n';
            //for (auto j : tmp)
                //cout << j << ' ';
            ll maxi = 0;
            for (auto j : tmp) {
                maxi = max(maxi, j);
            }
            //cout << maxi << '\n';
            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] != maxi)
                    continue;
                //cout << j << ' ';
                if (j-1 >= 0 && tmp[j-1] < tmp[j]) {
                    res.push_back(to_string(j+act)+" L");
                    tmp[j] += tmp[j-1];
                    tmp.erase(tmp.begin()+j-1);
                    break;
                }
                if (j+1 < tmp.size() && tmp[j] > tmp[j+1]) {
                    res.push_back(to_string(j+act)+" R");
                    tmp[j] += tmp[j+1];
                    tmp.erase(tmp.begin()+j+1);
                    break;
                }
            }
        }
    }
    if (!poss || i <= n) {
        cout << "NO\n";
        return 0;
    }
    else {
        cout << "YES\n";
        for (auto i : res) {
            cout << i << '\n';
        }
    }
}
 
/*
if (L == R)
    continue;
poss = 0;
ll maxiFirst = L, maxiLast = L;
 
if (a[maxiFirst] < a[R])
    maxiFirst = R;
if (a[maxiLast] <= a[R])
        maxiLast = R;
if (!poss)
    break;
if (maxiFirst != L) {
    for (int j = maxiFirst; j > L; j--) {
        res.push_back(to_string(j-L+act) + " L");
    }
    for (int j = maxiFirst; j < R; j++) {
        res.push_back(to_string(act) + " R");
    }
}
else {
    for (int j = maxiFirst; j < R; j++) {
        res.push_back(to_string(maxiLast-L+act) + " R");
    }
    for (int j = maxiFirst; j > L; j--) {
        res.push_back(to_string(j-L+act) + " L");
    }
}
*/