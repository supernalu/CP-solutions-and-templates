#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n, bucketSize, a[MAXN];
int segAnd[MAXN];
int whichBucket[MAXN];
int bucketStart[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        bucketSize = sqrt(n);
        int act = 1, bucket = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (act <= bucketSize) {
                whichBucket[i] = bucket;
                act++;
            }
            else {
                act = 1;
                bucket++;
                whichBucket[i] = bucket;
                bucketStart[bucket] = i;
                act++;
            }
        }
        whichBucket[n+1] = whichBucket[n]+1;
        
        for (int i = 1; i <= n; i++) {
            segAnd[i] = INT_MAX;
        }
        for (int i = 1; i <= n; i++) {
            segAnd[whichBucket[i]] = segAnd[whichBucket[i]] & a[i];
        }
        int q; cin >> q;
        while (q--) {
            int l, k; cin >> l >> k;
            if (a[l] < k) {
                cout << "-1 ";
                continue;
            }
            bool done = 0;
            int act = a[l];
            int i;
            for (i = l+1; i <= n && whichBucket[i] == whichBucket[l] && (act & a[i]) >= k; i++) {
                act = act & a[i];
            }
            if (whichBucket[i] == whichBucket[l]) { 
                cout << i-1 << ' ';
                continue;
            }
            int h = n+1;
            for (int j = whichBucket[i]; j <= whichBucket[n]; j++) {
                if ((act & segAnd[j]) >= k) {
                    
                    act = act & segAnd[j];
                    continue;
                }
                
                for (h = bucketStart[j]; h <= n && whichBucket[h] == whichBucket[bucketStart[j]] && (act & a[h]) >= k; h++) {
                    act = act & a[h];
                }
                break;
            }
            cout << h-1 << ' ';
        }
        cout << '\n';

    }
}