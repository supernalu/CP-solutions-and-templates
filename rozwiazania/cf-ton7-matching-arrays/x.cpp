#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, k;
int a[MAXN], b[MAXN], idA[MAXN], idB[MAXN];
bool cmpA(int c, int d) {
    if (a[c] == a[d])
        return c < d;
    return a[c] < a[d];
}
bool cmpB(int c, int d) {
    if (b[c] == b[d])
        return c < d;
    return b[c] < b[d];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            idA[i] = i;
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            idB[i] = i;
        }
        sort(idA+1, idA+n+1, cmpA);
        sort(idB+1, idB+n+1, cmpB);
        int tmp[MAXN], act = n;
        for (int i = k; i > 0; i--) {
            tmp[act] = idB[i];
            act--;
        }
        for (int i = n; i > k; i--) {
            tmp[act] = idB[i];
            act--; 
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (a[idA[i]] > b[tmp[i]])
                res++;
        } 
        if (res != k) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int r[MAXN];
        for (int i = 1; i <= n; i++)
            r[idA[i]] = b[tmp[i]];
        for (int i = 1; i <= n; i++)
            cout << r[i] << ' ';
        cout << '\n';
    }
}