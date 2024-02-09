#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n, k, m;
char s[MAXN];
vector<int> wh[30];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 30; i++)
            wh[i].clear();
        cin >> n >> k >> m >> s+1;
        for (int i = 1; i <= m; i++) {
            wh[s[i]-'a'].push_back(i);
        }
        for (int i = 0; i < k; i++) {
            for (int h = 1; h <= n+1; h++)
                wh[i].push_back(m+h);
        }
        int dl = 0, act = 0;
        bool res = 0;
        vector<char> example;
        while (dl < n) {
            int newAct = 0;
            int when;
            for (int i = 0; i < k; i++) {
                //cout << *(upper_bound(wh[i].begin(), wh[i].end(), act)) << ' ';
                newAct = max(newAct, *(upper_bound(wh[i].begin(), wh[i].end(), act)));
                if (newAct == *(upper_bound(wh[i].begin(), wh[i].end(), act)))
                    when = i;
            }
             //cout << '\n';
            example.push_back((char)('a'+when));
            act = newAct;
            dl++;
            //cout << act << ' ';
        }

        if (act <= m) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
            for (auto i : example)
                cout << i;
            cout << '\n';
        }
        
    }
}