#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n, k, m;
char s[MAXN];
vector<int> wh[30];
bool dp[30][30][1010];
int last[MAXN][30];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> m >> s+1;
        for (int i = 1; i <= 28; i++) {
            for (int j = 0; j <= 28; j++) {
               for (int pref = 0; pref <= m; pref++)
                    dp[i][j][pref] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++) {
                if (s[i]-'a'+1 == j)
                    last[i][j] = i;
                else
                    last[i][j] = last[i-1][j];
            }
        }
        for (int znak = 1; znak <= 26; znak++)
            dp[znak][0][0] = 1;
        for (int pref = 0; pref <= m; pref++) {
            for (int dl = n; dl >= 0; dl--) {
                
                for (int znak = 1; znak <= k; znak++) {
                    if (dp[znak][dl][pref] == 1) {
                        dp[znak][dl][pref+1] = 1; 
                    }  
                }
            
                if (dl == n || pref == 0)
                    continue;
                int resActZnak = 1;
                for (int i = 1; i <= k; i++) {
                    if (dp[i][dl][pref] == 0)
                        resActZnak = 0;
                }
                if (resActZnak == 1) {
                    dp[s[pref]-'a'+1][dl+1][pref] = 1;
                    dp[s[pref]-'a'+1][dl+1][pref+1] = 1;
                }
            }
        }
        for (int pref = 0; pref <= m; pref++)  {
            for (int dl = 0; dl <= n; dl++) {
                for (int znak = 1; znak <= k; znak++)
                    cout << dp[znak][dl][pref] << '|';
                cout << ' ';
            }
            cout << '\n';
        }
        bool res = 1;
        for (int i = 1; i <= k; i++) {
            if (dp[i][n][m] == 0)
                res = 0;
        }
        if (res)
            cout << "YES\n";
        else {
            cout << "NO\n";
            vector<char> example;
            int pref = m;
            for (int dl = n; dl > 0; dl--) {
                for (int znak = 1; znak <= k; znak++) {
                    if (dp[znak][dl][pref] == 0) {
                        //cout << znak << ' ';
                        example.push_back((char)(znak+'a'-1));
                        pref = last[pref][znak]-1;
                        break;
                    }
                }
            }
            reverse(example.begin(), example.end());
            for (auto i : example)
                cout << i;
            cout << '\n';
        }
    }
}