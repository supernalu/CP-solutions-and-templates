#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int n;
pair<long long, long long> b[MAXN];
pair<long long, long long> wsp(int i, int j) {
    return {b[j].second*b[i].first-b[j].first*b[i].second,b[i].first-b[j].first};
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    double res = -1;
    pair<long long, long long> act;
    for (int i = 1; i <= n; i++) {
        cin >> b[i].first >> b[i].second;       
    }
    if (n == 1) {
        cout << "-1";
        return 0;
    }
    act = wsp(1, 2);
    res = max(res, (double)act.first/(double)act.second);
    int wh = 1;
    for (int i = 3; i <= n; i++) {
        pair<long long, long long> tmp1 = wsp(wh, i), tmp2 = wsp(i-1,i);
        if (((double)tmp1.first/(double)tmp1.second)<((double)tmp2.first/(double)tmp2.second)) {
            wh = i-1;
            act = tmp2;
        }
        else {
            act = tmp1;
        }
        res = max(res, (double)act.first/(double)act.second);
    }
    if (res < 0)
        cout << "-1";
    else
        printf("%.10lf", res);
}