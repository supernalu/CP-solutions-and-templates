#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 +10;
int t, n;
int ile[30], id[30], res[30];
char s[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s+1;
        for (char i = 'a'; i <= 'z'; i++) {
            ile[i-'a'] = 0;
            id[i-'a'] = i;
        }
        for (int i = 1; i <= n; i++) {
            ile[s[i]-'a']++;
        }

    }
}