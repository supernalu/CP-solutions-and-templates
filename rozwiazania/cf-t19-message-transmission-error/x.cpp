#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10; 
typedef long long ll;
constexpr ll MOD = 1e9+7;
constexpr ll p = 29;
int n;
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.length();
    ll numberA = 0, numberB = 0;
    for (int i = 0; i < n/2; i++) {
        //cout << i << ' ';
        numberA *= p;
        numberA %= MOD;
        numberA += (s[i]-'a'+1);
        numberA %= MOD;
    }
    //cout << '\n';
    ll act = 1;
    for (int i = n-1; i > n-n/2-1; i--) {
        //cout << i << ' ';
        numberB += act*(s[i]-'a'+1);
        numberB %= MOD;
        act *= p;
        act %= MOD;
    }
    int L = n/2, R = n-n/2-1;
    bool res = 0;
    for (; L < n-1; L++) {
        numberA *= p;
        numberA %= MOD;
        numberA += (s[L]-'a'+1);
        numberA %= MOD;
        numberB += act*(s[R]-'a'+1);
        numberB %= MOD;
        act *= p;
        act %= MOD;
        if (numberA == numberB) {
            res = 1;
            break;
        }
        R--;
    }
    if (res) {
        cout << "YES\n";
        for (int i = 0; i <= L; i++) {
            cout << s[i];
        }
    }
    else {
        cout << "NO\n";
    }
}