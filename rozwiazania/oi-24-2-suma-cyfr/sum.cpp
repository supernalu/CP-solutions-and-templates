#include <bits/stdc++.h>
using namespace std;

const long long limit = 1000000000000000001LL;

const int n = 200;
int s, m, q;

long long dp[205][205][205];
long long below[205];

int tens[205];

inline void add(long long &a, long long b) {
    a += b;
    if(a >= limit) {
        a = limit;
    }
}

void calculateTens() {
    tens[0] = 1 % m;
    for(int i = 1; i <= n; i++) {
        tens[i] = (tens[i - 1] * 10) % m;
    }
}

void calculateDP() {
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        below[i] = below[i - 1];
        for(int r = 0; r < m; r++) {
            for(int d = 0; d <= s; d++) {
                for(int c = 0; c <= min(9, d); c++) {
                    add(dp[i][r][d], dp[i - 1][(r - (c * tens[i - 1]) % m + m) % m][d - c]);
                    if(c > 0 && r == 0 && d == s) {
                        add(below[i], dp[i - 1][(r - (c * tens[i - 1]) % m + m) % m][d - c]);
                    }
                }
            }
        }
    }
}

void findAnswer(long long k) {
    k -= 1;
    
    int len;
    for(len = 1; len <= n; len++)
        if(below[len] > k && below[len - 1] <= k) 
            break;
    
    if(len == n + 1) {
        cout << "NIE\n";
        return;
    }
    
    k -= below[len - 1];
    
    int d = s;
    int r = 0;
    
    for(int i = len; i > 0; i--) {
        int start = (i == len);
        vector <long long> ans(10, 0);
        
        for(int c = start; c <= 9; c++) {
            if(d - c >= 0) add(ans[c], dp[i - 1][(r - (c * tens[i - 1]) % m + m) % m][d - c]);
        }
        
        for(int c = start; c <= 9; c++) {
            if(k >= ans[c]) {
                k -= ans[c];
            } else {
                r = (r - (c * tens[i - 1]) % m + m) % m;
                d = d - c;
                cout << c;
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> m >> q;
    
    calculateTens();
    calculateDP();
    
    while(q--) {
        long long k;
        cin >> k;
        findAnswer(k);
    }
}