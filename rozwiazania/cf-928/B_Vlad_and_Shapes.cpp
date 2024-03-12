#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e2 + 10;
typedef long long ll;
int t, n;
char grid[MAXN][MAXN];
int ones[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            ones[i] = 0;
            cin >> grid[i]+1;
            for (int j = 1; j <= n; j++)
                if (grid[i][j] == '1')
                    ones[i]++;
        }
        sort(ones+1, ones+n+1);
        int diff = 1;
        for (int i = 2; i <= n; i++)
            if (ones[i] != ones[i-1])
                diff++;
        if (diff < 3)
            cout << "SQUARE\n";
        else
            cout << "TRIANGLE\n";
        
    }
}