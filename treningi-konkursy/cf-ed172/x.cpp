#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n, k;
char s[MAXN];
ll suf[MAXN];
int prefMax[MAXN];
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
        suf[n+1] = 0;
        for (int i = n; i > 0; i--) {
            //cout << suf[i] << ' ';
            suf[i] += suf[i+1];
            //cout << i << ' '  << suf[i] << ' ';
        }
        
        prefMax[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (suf[i] >= suf[prefMax[i-1]])
                prefMax[i] = i;
            else
                prefMax[i] = prefMax[i-1];
        }
        int res = 1;
        ll sum = 0;
        ll dod = 0;

        vector<ll> best;
        int act = n;
        while (act > 0 && suf[prefMax[act]] > 0) {
            best.push_back(suf[prefMax[act]]);
            act = prefMax[act]-1;
        }
        
        for (auto u : best) {
            //cout << u << ' ';
            res++;
            dod += u;
            sum += u;
            if (sum >= k)
                cout << res << '\n';
        }
        for (int i = best[0]+1; i <= n; i++) {
            
        }
        if (sum < k)
            cout << "-1\n";
        
    }
}