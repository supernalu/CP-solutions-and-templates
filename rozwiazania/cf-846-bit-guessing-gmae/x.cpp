#include <bits/stdc++.h>
using namespace std;
int t;
int diff[31];
int main() {
    diff[0] = 1;
    for (int i = 1; i < 31; i++) {
        diff[i] = diff[i-1] + (1 << i);
    }

    cin >> t;
    while (t--) {
        int res = 0;
        while (true) {
            int cnt; cin >> cnt;
            if (cnt == 0)
                break;
            res += diff[cnt-1];
            cout << "- " << diff[cnt-1] << '\n';
            cout.flush();
        }
        cout << "! " << res << "\n";
        cout.flush();
    }
}