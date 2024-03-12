#include <bits/stdc++.h>
using namespace std;
int t;
void edgeCaseRow(int n, int m) {

}
int main() {
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int odlLD, odlRU;
        cout << "? 1 1\n";
        cout.flush();
        cin >> odlLD;

        cout << "? " << n << ' ' << m << '\n';
        cout.flush();
        cin >> odlRU;
        pair<int, int> firstOpt = {1+odlLD, m-odlRU}, secOpt = {n-odlRU, 1+odlLD};
        if (firstOpt == secOpt || secOpt.first < 1 || secOpt.second > m) {
            cout << "! " << firstOpt.first << ' ' << firstOpt.second << '\n';
            cout.flush();
            continue;
        }
        else if (firstOpt.first > n || firstOpt.second < 1) {
            cout << "! " << secOpt.first << ' ' << secOpt.second << '\n';
            cout.flush();
            continue;
        }
        cout << "? 1 " << m << '\n';
        cout.flush();
        int checker; cin >> checker;
        if (max(odlLD, odlRU) == checker) {
            cout << "! " << firstOpt.first << ' ' << firstOpt.second << '\n';
            cout.flush();
            continue;
        }
        else {
            cout << "! " << secOpt.first << ' ' << secOpt.second << '\n';
            cout.flush();
            continue;
        }
    }
}