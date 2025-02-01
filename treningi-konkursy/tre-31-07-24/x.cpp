#include <bits/stdc++.h>
constexpr int MAXN = 3e5+10;
using namespace std;
int t;
int n, a[MAXN];
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i<= n; i++) {
            cin >> a[i];
        }
        cin >> s;
        int ile1 = 0, ile0 = 0;
        queue<int>q, q2;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ile1++;
            }
            else
                ile0++;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && a[i+1] <= ile0) {
                q.push(i+1);
            }
            else if (s[i] == '0' && a[i+1] > ile0)
                q2.push(i+1);
        
        }
        while(!q.empty()) {
            swap(a[q.front()], a[q2.front()]);
            q.pop();
            q2.pop();
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
}