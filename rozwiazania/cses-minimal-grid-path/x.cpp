#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e3+10;
constexpr long long MOD=1e15+7;
constexpr long long p = 31;
int n;
char s[MAXN][MAXN];
char res[2*MAXN];
bool good[MAXN][MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i]+1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            good[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            good[i][j] = 1;
    }
    good[1][1] = 1;
    res[1] = s[1][1];
    for (int i = 2; i <= 2*n-1; i++) {
        if (i <= 2*n-i) {
            for (int j = 1; j <= i; j++) {
                if (!good[j-1][i-j+1] && !good[j][i-j])
                    good[j][i-j+1] = 0;
            }
            res[i] = 'Z';
            for (int j = 1; j <= i; j++) {
                if (good[j][i-j+1])
                    res[i] = min(res[i], s[j][i-j+1]);
            }
            for (int j = 1; j <= i; j++) {
                if (s[j][i-j+1] != res[i])
                    good[j][i-j+1] = 0;
            }  
        }  
        else {
            for (int j = 1; j <= 2*n-i; j++) {
                if (!good[n-j][i-n+j] && !good[n-j+1][i-n+j-1])
                    good[n-j+1][i-n+j] = 0;
            }
            res[i] = 'Z';
            for (int j = 1; j <= 2*n-i; j++) {
                if (good[n-j+1][i-n+j])
                    res[i] = min(res[i], s[n-j+1][i-n+j]);
            }
            for (int j = 1; j <=  2*n-i; j++) {
                if (s[n-j+1][i-n+j] != res[i])
                    good[n-j+1][i-n+j] = 0;
            }  
        } 
    }
    for (int i = 1; i <= 2*n-1; i++)
        cout << res[i];


    
}