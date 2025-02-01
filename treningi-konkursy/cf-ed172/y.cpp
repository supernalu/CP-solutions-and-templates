#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n, k;
char s[MAXN];
ll suf[MAXN];
int prefMax[MAXN], sufMax[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> t;
    while (t--) {
        cin >> n >> k >> s+1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1')
                suf[i] = 1;
            else
                suf[i] = -1;
                //cout << suf[i] << ' ';
        }
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        suf[n+1] = 0;
        for (int i = n; i > 0; i--) {
            //cout << suf[i] << ' ';
            suf[i] += suf[i+1];
            //cout << i << ' '  << suf[i] << ' ';
        }
        
        prefMax[2] = 2;
        for (int i = 2; i <= n; i++) {
            if (suf[i] >= suf[prefMax[i-1]])
                prefMax[i] = i;
            else
                prefMax[i] = prefMax[i-1];
        }
        
        sufMax[n] = n;
        for (int i = n-1; i > 0; i--) {
            if (suf[i] >= suf[sufMax[i+1]])
                sufMax[i] = i;
            else
                sufMax[i] = sufMax[i+1];
        }
        
        ll res = 1;
        ll sum = 0;
        ll dod = 0;

        vector<ll> bestL, bestR;
        int act = n;
        int newAct = prefMax[n];
        while (act > 0 && suf[prefMax[act]] > 0) {
            bestL.push_back(suf[prefMax[act]]);
            act = prefMax[act]-1;
        }
        if (bestL.empty()) {
            cout << "-1\n";
            continue;
        }
        act = newAct+1;
        while (act <= n && suf[sufMax[act]] > 0) {
            bestR.push_back(suf[sufMax[act]]);
            act = sufMax[act]+1;
            //cout << act << ' ';
        }
        /*
        for (auto u : bestL)
            cout << u << ' ';
        cout << '\n';
        for (auto u : bestR)
            cout << u << ' ';
        cout << '\n';
        */
        ll l = 0, r = 0;
        while (l < bestL.size() || r < bestR.size()) {
            //cout << sum << ' ';
            if (r == bestR.size() || (l < bestL.size() && (dod+bestL[l] >= bestR[r]))) {
                res++;
                dod+=bestL[l];
                l++;
                sum+=dod;
            }
            else {
                sum+=bestR[r];
                dod+=bestR[r];
                res++;
                r++;
            }
            //cout << sum << ' ' << l << ' ' << r << '\n';
            if (sum >= k) {
                cout << res << '\n';
                break;
            }
        }
        
        
        if (sum < k)
            cout << "-1\n";
        
    }
}