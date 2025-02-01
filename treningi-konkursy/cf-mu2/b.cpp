#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n, q; 
int a[MAXN];
int ile[10*MAXN+10];
int id[10*MAXN+10];
int pref[10*MAXN+10];
vector<bool> done(10*MAXN+10, 0);
void sieve() {
    int act = 0;
    for (int i = 2; i < 10*MAXN; i++) {
        id[i] = act;
        if (done[i])
            continue;
        act++;
        id[i] = act;
        for (int j = i; j < 10*MAXN; j+=i) {
            done[j] = 1;
            pref[act] += ile[j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ile[a[i]]++;
    }
    sieve();
    pref[0] = 0;
    for (int i = 1; i < 10*MAXN; i++)
        pref[i] += pref[i-1];
    //for (int i = 1; i <= 20; i++) 
        //cout << id[i] << ' ';
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        if (l > 10*MAXN-1) {
            cout << "0\n";
            continue;
        }
        cout << pref[id[min(r, 10*MAXN-1)]]-pref[id[l-1]] << '\n';
    }
}