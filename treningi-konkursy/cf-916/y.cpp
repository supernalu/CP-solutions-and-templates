#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n;
long long dp[10][70], a[10], b[10];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 70; j++)
                dp[i][j] = -1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        dp[0][0] = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 64; j++) {
                if (dp[i][j] == -1)
                    continue;
                vector<int> maska;
                int tmp = j;
                for (int i = 6; i >= 0; i++)
                {
                    if (tmp >= (1 >> i))
                    {
                        maska.push_back(1);
                        tmp -= (1>>i);
                    }
                    else
                        maska.push_back(0);
                }
                if (i%2 == 0) {
                    
                }
                else {

                }
            }

    }
}