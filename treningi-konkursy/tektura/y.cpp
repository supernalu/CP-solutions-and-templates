#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100000];
bool res[100000];
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        a[1] = 0;
        for (int i = 2; i <= n; i++) {
            cout << "? 1 " << i << '\n';
            cout.flush();
            cin >> a[i];
        }
        int longest_prefix = 1;
        while(a[longest_prefix] == 0)
            longest_prefix++;
        longest_prefix-=2;
        bool known = 1;
        if (a[n] == 0)
            known = 0;
        if (!known) {
            cout << "! IMPOSSIBLE\n";
            cout.flush();
            continue;
        }
        int sum = 0;
        int ile = 0;
        //cout << longest_prefix << '\n';
        for (int i = n-1; i >= longest_prefix; i--) {
            if (a[i+1] != a[i])
                res[i+1] = 1;
            else
                res[i+1] = 0;
            if (res[i+1] == 1)
                ile++;
            else
                sum += ile;
        }
        for (int i = longest_prefix; i > 0; i--) {
            if (sum < a[n]) {
                res[i] = 0;
                sum += ile;
            }
            else
                res[i] = 1;
        }
        cout << "! ";
        for (int i = 1; i <= n; i++)
            cout << res[i];
        cout << '\n';
        cout.flush();
    }
    
}