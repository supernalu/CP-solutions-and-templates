#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        bool AliceWins = 0;
        for (int i = 2; i*i <= n; i++) {
            int ile = 0;
            while (n%i == 0) {
                n/=i;
                ile++;
            }
            if (ile%2 == 0 && ile != 0)
                AliceWins = 1;
        }
        if (AliceWins)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}