#include <bits/stdc++.h>
using namespace std;
set<int> s;
void init() {
    pair<int, int> keyboard[] = {{4, 2}, {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};
    for (int i = 0; i < 10; i++)
        s.insert(i);
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (keyboard[i].first <= keyboard[j].first && keyboard[i].second <= keyboard[j].second)
                s.insert(10*i+j);
        }
    }
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (keyboard[i].first <= keyboard[j].first && keyboard[i].second <= keyboard[j].second && keyboard[j].first <= keyboard[k].first && keyboard[j].second <= keyboard[k].second)
                    s.insert(100*i+10*j+k);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); init();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n; 
        auto u = s.lower_bound(n); u--;
        int tmp1 = *(s.lower_bound(n)), tmp2 = *(u);
        if (abs(tmp1-n) < abs(tmp2-n))
            cout << tmp1 << '\n';
        else
            cout << tmp2 << '\n';
    }   
}