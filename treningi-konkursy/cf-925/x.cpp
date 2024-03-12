#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, n, m;
string a[MAXN];
int ileZer[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll suma = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ileZer[i] = 0;
            for (int j = a[i].size()-1; j >= 0; j--) {
                if (a[i][j] != '0')
                    break;
                ileZer[i]++;
            }
            suma += a[i].size();
        }
        sort(ileZer + 1, ileZer + n + 1);
        for (int i = n; i > 0; i-=2) {
            suma -= ileZer[i];
        }
        if (suma > m) {
            cout << "Sasha\n";
        }
        else {
            cout << "Anna\n";
        }


    }
}