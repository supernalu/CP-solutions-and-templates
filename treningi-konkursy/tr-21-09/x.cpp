#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;
int t, n;
int il[2];
bool dp[110][110][2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        il[0] = 0; il[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            int a; cin >> a;
            il[(INF+a)%2]++;
        }
        if (il[1]%2)
            cout << "BOB\n";
        else 
            cout << "ALICE\n";

    }
}