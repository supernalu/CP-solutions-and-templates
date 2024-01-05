#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if (n%4 == 2 || n%4 == 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int st = 1;
    vector<int> s1, s2;
    if (n%4 == 3) {
        s1.push_back(1); s1.push_back(2); s2.push_back(3);
        st = 4;
    }
    for (; st <= n; st+=4) {
        s1.push_back(st); s1.push_back(st+3);
        s2.push_back(st+1); s2.push_back(st+2);
    }
    cout << s1.size() << '\n';
    for (auto i : s1)
        cout << i << ' ';
    cout << '\n' << s2.size() << '\n';
    for (auto i : s2)
        cout << i << ' ';
}
