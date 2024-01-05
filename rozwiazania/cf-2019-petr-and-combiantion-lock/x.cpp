#include <bits/stdc++.h>

using namespace std;

bool dp[360][16];

int n;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dp[0][0] = 1;

    cin >> n;

    for (int j = 1; j <= n; j++)
    {
        int a;

        cin >> a;

        for (int i = 0; i < 360; i++)
        {
            if (dp[(i + a)%360][j-1] || dp[(i - a + 360)%360][j-1])
                dp[i][j] = 1;
        }
    }

    if (dp[0][n])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

}