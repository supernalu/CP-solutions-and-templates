#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 10;
int n, a[MAXN], ile[MAXN]; 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ile[a[i]]++;
    }
    sort(ile+1, ile+n+1);
    int R = n, L = 1;
    int zapas, res = 0;
    for ( ; L <= R; R--) {
        if (ile[R] == 0)
            break;
        res++;
        zapas = ile[R]-1;
        while (zapas > 0 && L < R) {
            int change = min(ile[L], zapas);
            zapas -= change;
            ile[L] -= change;
            if (ile[L] == 0)
                L++;
        }

    }
    cout << res << '\n';

    
}