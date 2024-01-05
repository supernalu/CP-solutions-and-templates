#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;

int n;
long long a[MAXN], d;
int dp[MAXN];
int parent[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> d;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int id = 0;

        for (int j = 0; j < i; j++)
        {

            if (abs(a[i]-a[j]) < d)
                continue;

            if (dp[j] > dp[id])
                id = j;
        }
        parent[i] = id;
        dp[i] = dp[id]+1;
    }

    int id = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > dp[id])
            id = i;
    }

    cout << dp[id] << '\n';

    vector<int> res;

    while (id != 0)
    {
        res.push_back(id);
        id = parent[id];
    }
    reverse(res.begin(), res.end());
    for (auto i : res)
        cout << i << ' ';

    
}