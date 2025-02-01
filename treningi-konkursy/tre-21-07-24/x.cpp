#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t; 
int n;
pair<int, int> h, al[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> h.first >> h.second;
        for (int i = 1; i <= n; i++)
            cin >> al[i].first >> al[i].second;
        sort(al+1, al+n+1);
        int res = 0;
        if (al[n] < h) {
            res += 60-h.second+al[1].second;
            res += (23-h.first+al[1].first)*60;
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (h <= al[i]) {
                    if (h.first == al[i].first)
                        res = al[i].second-h.second;
                    else {
                        res += al[i].second+60-h.second;
                        res += (al[i].first-h.first-1)*60;
                    }
                    break;
                }
            }
        }
        cout << res/60 << ' ' << res%60 << '\n';

    
    }
}