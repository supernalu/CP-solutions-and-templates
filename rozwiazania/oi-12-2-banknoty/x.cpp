//!Do poprawy!
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 210;
constexpr int MAXK = 20010;

int n, k;
int b[MAXN], c[MAXN];
int dp[MAXN][MAXK];
int parent[MAXN][MAXK];
int GlobalIterator = 0;

bool cmp(int a, int d)
{   
    if (a > d)
    {
        if (dp[GlobalIterator][a] == dp[GlobalIterator][d] + (a-d)/b[GlobalIterator])
        {
            return 1;
        }
        else
            return dp[GlobalIterator][a] < dp[GlobalIterator][d] + (a-d)/b[GlobalIterator];
    }
    else 
    {
        if (dp[GlobalIterator][d] == dp[GlobalIterator][a] + (d-a)/b[GlobalIterator])
        {
            return 1;
        }
        else
            return dp[GlobalIterator][d] > dp[GlobalIterator][a] + (d-a)/b[GlobalIterator];
    }

}

void solve(int nomination)
{
    set<int, decltype(&cmp)> s(&cmp);
    for (int st = nomination; st < 2*nomination && st <= k; st++)
    {
        s.clear();
        for (int i = st; i <= k; i += nomination)
        {
            if (s.size() == c[GlobalIterator])
                s.erase(i - c[GlobalIterator]);
            int tmp = *(s.begin());
            dp[GlobalIterator+1][i] = min(dp[GlobalIterator][i], dp[GlobalIterator][tmp] + (i - tmp)/nomination);


            s.insert(i);
        }
    }

    GlobalIterator++;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    
    cin >> k;

    for (int i = 1; i <= n; i++)
        solve(b[i]);
    
    cout << dp[n][k];
}