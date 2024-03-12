#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n;
char trump;
bool cmp (string a, string b) {
    if (a[1] == b[1]) 
        return a[0] < b[0];
    return a[1] < b[1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> trump;
        vector<string> nonTrumpCards;
        vector<string> TrumpCards;
        for (int i = 1; i <= 2*n; i++) {
            string tmp; cin >> tmp;
            if (tmp[1] == trump)
                TrumpCards.push_back(tmp);
            else
                nonTrumpCards.push_back(tmp);
        }
        sort(nonTrumpCards.begin(), nonTrumpCards.end(), cmp);
        sort(TrumpCards.begin(), TrumpCards.end(), cmp);
        bool poss = 1;
        vector<string> res;
        auto wsT = TrumpCards.begin();
        int ileType = 0;
        string last = "00";
        for (auto i : nonTrumpCards) {
            if (i[1] != last[1]) {
                if (ileType%2 == 0) {
                    res.push_back(i);
                    ileType = 1;
                }
                else {
                    if (wsT == TrumpCards.end()) {
                        poss = 0;
                        break;
                    }
                    res.push_back(*wsT);
                    wsT++;
                    res.push_back(i);
                    ileType = 1;
                }
            }
            else {
                res.push_back(i);
                ileType++;
            }
            last = i;
        }
        for (; wsT != TrumpCards.end(); wsT++) {
            res.push_back(*wsT);
        }
        if (!poss) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (int i = 0; i < 2*n; i+=2) {
            cout << res[i] << ' ' <<  res[i+1] << '\n'; 
        }


    }
}