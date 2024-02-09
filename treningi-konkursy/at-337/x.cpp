#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int power[30];
    power[0] = 1;
    int m = 1, id = 1;

    while (m < n) {
        m *= 2;
        power[id] = m;
        id++;
    }
    id--;
    vector<int> bottlesForFriend[30];
    cout << id << '\n';
    cout.flush();
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        for (int j = id; j >= 0; j--) {
            if (tmp >= power[j]) {
                tmp -= power[j];
                bottlesForFriend[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < id; i++) {
        cout << bottlesForFriend[i].size() << ' ';
        for (auto j : bottlesForFriend[i])
            cout << j << ' ';
        cout << '\n';
        cout.flush();
    }
    string a; cin >> a;
    int k = a.size()-1;
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '1')
            res += power[i];
        k--;
    }
    if (res == 0)
        cout << n << '\n';
    else
        cout << res << '\n';
    cout.flush();
    return 0;
}