#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n;
int power[20];
int res[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    power[0] = 1;
    for (int i = 1; i < 20; i++)
        power[i] = power[i-1]*2;
    cin >> t;
    while (t--) {
        cin >> n; 
        int ress;
        if (n%2 == 1) {
            ress = n;
        }
        else {
            ress = 0;
            for (int i = 0; i < 20 && power[i] <= n; i++)
                ress += power[i];
        }
        int nn = n;
        if (n%2) {
            res[n] = n;
            nn--;
        }
        int maxi = 0;
        while (power[maxi] <= n) {
            maxi++;
        }
        maxi--;
        cout << ress << '\n';
        for (int i = power[maxi]+1; i <= nn; i++)
            res[i-power[maxi]] = i; 
        res[nn+1] = 2;
        res[nn+2] = 1;
        res[nn+3] = 3;
        res[nn+4] = 4;
        res[nn+5] = 5;
        for (int i = nn+6; i <= power[maxi]+nn; i++)
            res[i] = i-nn;
        for (int i = 1; i <= n; i++)
            cout << res[i] << ' ';
        cout << '\n';

    }
}