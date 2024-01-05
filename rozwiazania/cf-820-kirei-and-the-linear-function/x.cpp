#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
int t, n, q, w, pref[MAXN]; 
vector<int> ile[9];
char c[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> c+1 >> w >> q;
        n = strlen(c+1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) 
            pref[i] = (pref[i-1]+(c[i]-'0'))%9;
        for (int i = 0; i < 9; i++)
            ile[i].clear();
        for (int i = w; i <= n; i++)
            ile[(pref[i]-pref[i-w]+9)%9].push_back(i-w+1);
        while (q--) {
            int l, r, k; cin >> l >> r >> k;
            pair<int, int> res = {1e9 + 10, 1e9 + 10};
            int wspK = (pref[r]-pref[l-1]+9)%9;
            bool done = 0;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if ((i == j && ile[i].size() < 2) || ile[i].size() == 0 || ile[j].size() == 0 || (i*wspK+j)%9 != k)
                        continue;
                    done = 1;
                    pair<int, int> tmp;
                    if (i == j) {
                        tmp =  {ile[i][0], ile[i][1]};
                    }
                    else {
                        tmp = {ile[i][0], ile[j][0]};
                    }
                    if (tmp < res) res = tmp;
                }
                
            }
            if (!done) cout << "-1 -1\n";
            else cout << res.first << ' ' << res.second << '\n';
        }
    }
}