#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, k;
long long a[MAXN], b[MAXN]; 
int ida[MAXN], idb[MAXN];
bool taken[MAXN];
bool cmp(int u, int v)
{
    if (a[u]-b[u] == a[v]-b[v])
        return a[u] > a[v];
    return a[u]-b[u] > a[v]-b[v];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int perm[10];
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            taken[i] = 0;
            ida[i] = i;
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            idb[i] = i;
            cin >> b[i];
        }
        sort(ida+1, ida+n+1, cmp);
        //for (int i = 1; i <= n; i++)
            //cout << ida[i] << ' ' << idb[i] << '\n';
        int wsa = 1, wsb = n;
        for (int i = 1; i <= n; i++)
        {
            //cout << i << ' ';
            if (i%2) {
                res += a[ida[wsa]]-1; 
                wsa++;
            }
            else
            {
                res -= b[ida[wsb]]-1;
                wsb--;
            }
        }
        cout << res << '\n';
    }


}