#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;
constexpr int SIZE = 256;
constexpr int POT = 8;

int n, d;

long long h[MAXN];
int dp[MAXN];
int parent[MAXN];
int K[400];
int id[MAXN];
pair<int, int> range[MAXN];

bool cmp (int a, int b)
{
    if (h[a] == h[b])
        return a < b;
    return h[a] < h[b];
}

void update(int a)
{
    int maxi = -1e9;
    int L = a - a%SIZE;

    cout << L << ": ";

    for (int i = L+1; i <= SIZE && i <= n; ++i)
    {
        cout << dp[i] << ' ';
        maxi = max(maxi, dp[i]);
    }

    cout  << '\n';
    K[(L<<POT)] = maxi;
}
int query(int L, int R)
{
    int maxi = -1e9;
    for (; ((L>>POT)<<POT)!= L && L <= R; ++L)
        maxi = max(maxi, dp[L]);
    for (; L + SIZE-1 <= R; L += SIZE)
        maxi = max(maxi, K[(L << POT)]);
    for(; L <= R; ++L)
        maxi = max(maxi, dp[L]);

    return maxi;
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> d;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        id[i] = i;
        dp[i] = -1e9;
    }
    if (d == 0)
    {
        cout << n << '\n';
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        return 0;
    }

    for (int i = 1; i <= n+255/SIZE; i++)
    {
        K[i] = -1e9+10;
    }
    dp[1] = 1; parent[1] = 0; update(1);

    sort(id+1, id+n+1, cmp);

    //cout << "LOL";
    
    
    int L = 1, R = 1;
    for (int i = 1; i <= n; i++)
    {
        while (h[id[i]]-h[id[L]] >= d && L <= i)
            L++;    
        while (h[id[R]]-h[id[i]] < d && R <= n+1)
            R++;
        
        range[id[i]] = {L, R-1};
    }
    
    for (int i = 1; i <= n; i++)
    {
        long long tmp1 = query(1, range[i].first-1), tmp2 = query(range[i].second+1, n);

        if (max(tmp1, tmp2) < 1)
        {
            dp[i] = 1;
            parent[i] = 0;

            continue;
        }
        dp[i] = max(tmp1, tmp2)+1;

        cout << tmp1 << ' ' << tmp2 << ' ';

        update(id[i]);
    }

}