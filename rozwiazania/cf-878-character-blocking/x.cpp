#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 4e5 + 10;;
int t, n;
char s[3][MAXN];
int unlock[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s[1]+1 >> s[2]+1;
        n = strlen(s[1]+1);
        set<int> WrongPositions;
        for (int i = 1; i <= n; i++) 
            if (s[1][i] != s[2][i])
                WrongPositions.insert(i);
        int time, q; cin >> time >> q;
        for (int i = 1; i <= q; i++) {
            unlock[i] = -1;
        }
        for (int query = 1; query <= q; query++) {
            if (unlock[query] != -1) {
                if (s[1][unlock[query]] != s[2][unlock[query]])
                    WrongPositions.insert(unlock[query]);
            }
            int type; cin >> type;
            if (type == 3) {
                if (WrongPositions.empty())
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else if (type == 1) {
                int pos; cin >> pos;
                unlock[time+query] = pos;
                if (s[1][pos] != s[2][pos])
                    WrongPositions.erase(pos);
            }
            else {
                int t1, i1, t2, i2; cin >> t1 >> i1 >> t2 >> i2;
                if (WrongPositions.find(i1) != WrongPositions.end()) 
                    WrongPositions.erase(i1); 
                if (WrongPositions.find(i2) != WrongPositions.end()) 
                    WrongPositions.erase(i2); 
                swap(s[t1][i1], s[t2][i2]);
                if (s[1][i1] != s[2][i1])
                    WrongPositions.insert(i1);
                if (s[1][i2] != s[2][i2])
                    WrongPositions.insert(i2);
            }
        }

    }
}