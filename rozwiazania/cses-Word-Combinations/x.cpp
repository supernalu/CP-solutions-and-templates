#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e5 + 10;
constexpr ll MOD = 1e9 + 7;
constexpr ll P = 29;
string s;
int n, k;
string w[MAXN];
ll hashh[5010];
ll hashOfW[MAXN];
ll powerOfP[5010];
ll dp[5010];
unordered_set<ll> wasThere;
void hashing(string u, int uN, ll& storage) {
    assert(u.size() >= uN + 1);
    storage = 0;
    for (int i = 0; i <= uN; i++) {
        storage *= P;
        storage += (u[i]-'a'+1);
        storage %= MOD;
    }
}
int main() {
    powerOfP[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        powerOfP[i] = (P*powerOfP[i-1])%MOD;
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> k;
    n = s.size();
    for (int i = 0; i < n; i++) { //sq
        hashing(s, i, hashh[i]);
    }
    /*
    for (int i = 0; i < n; i++) // lin-log
        wasThere[hashh[i]] = 0;
    for (int i = 0; i < n-1; i++) { //sq-log
        for (int j = i+1; j < n; j++) {
            wasThere[((hashh[j]-(powerOfP[j-i]*hashh[i])%MOD)+MOD)%MOD] = 0;
        }
    }
    */
    for (int i = 1; i <= k; i++) { // O(Sigma w[i].size() + k log)
        cin >> w[i];
        hashing(w[i], w[i].size()-1, hashOfW[i]);
        wasThere.insert(hashOfW[i]);
        //wasThere[hashOfW[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        dp[i] = wasThere.count(hashh[i]);
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            dp[j] += dp[i]*wasThere.count(((hashh[j]-(powerOfP[j-i]*hashh[i])%MOD)+MOD)%MOD);
            dp[j] %= MOD;
        }
        //cout << dp[i] << '\n';
    }
    cout << dp[n-1];

}