#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t; 
int n;
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int res = 0;
        int maksG = 0, maksD = 0;
        int act = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] != s[i-1]) {
                if (s[i] == '<')
                    act = maksD;
                else
                    act = maksG;
            }
            if (s[i] == '<') {
                act++;
                if (act > maksG) {
                    maksG = act;
                    res++;
                }
            }
            else if (s[i] == '>') {
                act--;
                if (act < maksD) {
                    maksD = act;
                    res++;
                }
            }
        }
        cout << res+1 << '\n';
       
    }
}