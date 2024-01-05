#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

vector<int> a(MAXN, 0);
vector<int> b(MAXN, 0);

int sc[MAXN];

vector<int> wys(5*MAXN, 0);

int dp[MAXN];
int parent[MAXN];

vector<int>road;

bool p(int q, int w)
{
    return a[q] < a[w]; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        b[i] = i;
    }

    a.resize(n+1);
    b.resize(n+1);

    sort(b.begin() + 1, b.end(), p);

    sc[b[1]] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        //cout << b[i] << ' ';

        if (a[b[i]] == a[b[i-1]])        
            sc[b[i]] = sc[b[i-1]];        
        else if (a[b[i]] == a[b[i-1]] + 1)        
            sc[b[i]] = sc[b[i-1]] + 1;
        else
        {
            sc[b[i]] = sc[b[i-1]] + 2;
        }    
    }

    dp[1] = 1;
    wys[sc[1]] = 1;

    for (int i = 2; i <= n; i++)
    {
        //cout << sc[i] << ' ';

        if (wys[sc[i] - 1] == 0)
        {
            dp[i] = 1;
            wys[sc[i]] = i;
            parent[i] = 0;

            continue;
        }

        dp[i] = dp[wys[sc[i] - 1]] + 1;
        wys[sc[i]] = i;

        parent[i] = wys[sc[i] - 1];
    }
    //cout << endl;

    int res = 0, it = 0;

    for (int i = 1; i <= n; i++)
    {
        //cout << dp[i] << ' ';

        if (dp[i] > res)
        {
            res = dp[i];
            it = i;
        }
    }

    cout << res << endl;

    while (parent[it] != 0)
    {
        road.push_back(it);

        it = parent[it];
    }

    cout << it << ' '; 

    reverse(road.begin(), road.end());

    for (int i = 0; i < road.size(); i++)
        cout << road[i] << ' '; 

    

}