#include <bits/stdc++.h>
using namespace std;
int t;
long long h, w, xa, ya, xb, yb;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> h >> w >> xa >> ya >> xb >> yb;
        if (xb-xa <= 0) {
            cout << "Draw\n";
            continue;
        }
        pair<long long, long long> a, b;
        long long steps = xb-xa;
        a.first = max(1ll, ya-(steps+1)/2); a.second = min(w, ya+(steps+1)/2);
        b.first = max(1ll, yb-(steps)/2); b.second = min(w, yb+(steps)/2);
        //cout << steps << ' ' << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << '\n';
        if (steps%2 == 1 && a.first <= b.first && b.second <= a.second)
            cout << "Alice\n";
        else if (steps%2 == 0 && b.first <= a.first && a.second <= b.second)
            cout << "Bob\n";
        else
            cout << "Draw\n";
    }
    
}