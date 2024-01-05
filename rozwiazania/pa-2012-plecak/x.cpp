#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 201;

constexpr int MAXP = 1e4 + 1;

int n;

int p;

pair<int, int> item[MAXN];

vector <int> adj[MAXN];

bool dp[MAXP][MAXN];

bool f[MAXN][MAXN];


int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> p;

    for (int i = 1; i <= n; i++)
        cin >> item[i].first >> item[i].second;

    f[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int j = i;

        while (j != 0) {

            f[i][j] = 1;

            j = item[j].first;

            
        } 

        

        f[i][0] = 1;
    }

    

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)       
            if (f[i][item[j].first] == 1)            
                adj[i].push_back(j);
            

    

   dp[0][0] = true;

    for (int i = 0; i <= p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 0)
                continue;

            for (auto k : adj[j])
            {
                if (i + item[k].second > p)
                    continue;

                dp[i + item[k].second][k] = true;
            }
        }
    }

    for (int i = p; i >= 0; i--)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j])
            {
                cout << i;
                return 0;
            }

        }
    }

}