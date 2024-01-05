#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e4 + 10;

int maxi = 1;

string s;

vector<int> adj[MAXN];

int build_a_tree(int k)
{
    //cout << k << ' ';

    if (s[k] == '0')
    {
        return k;
    }
    else if (s[k] == '2')
    {
        adj[k+1].push_back(k+2);
        int h = build_a_tree(k+1);
        adj[k+1].push_back(h+2);
        h = build_a_tree(h+1);   

        return h; 
    }
    else
    {
        adj[k+1].push_back(k+2);     
        int h = build_a_tree(k+1);   

        return h;
    }
}

/*
-Wall -Wextra
*/

int dpMAX[MAXN][3];
int dpMIN[MAXN][3];

int dfs(int v)
{
     //-Wall

    for (auto u : adj[v])
    {
        dfs(u);
    }

    if (adj[v].size() == 0)
    {
        dpMAX[v][0] = 1;
        dpMAX[v][1] = 0;
        dpMAX[v][2] = 0;

        dpMIN[v][0] = 1;
        dpMIN[v][1] = 0;
        dpMIN[v][2] = 0;
    }
    else if (adj[v].size() == 1)
    {
        int u = adj[v][0];

        dpMAX[v][0] = max(dpMAX[u][1], dpMAX[u][2]) + 1;
        dpMAX[v][1] = max(dpMAX[u][0], dpMAX[u][2]);
        dpMAX[v][2] = max(dpMAX[u][1], dpMAX[u][0]);

        dpMIN[v][0] = min(dpMIN[u][1], dpMIN[u][2]) + 1;
        dpMIN[v][1] = min(dpMIN[u][0], dpMIN[u][2]);
        dpMIN[v][2] = min(dpMIN[u][1], dpMIN[u][0]);
    }
    else
    {
        int u1 = adj[v][0], u2 = adj[v][1];

        dpMAX[v][0] = max(dpMAX[u1][1] + dpMAX[u2][2], dpMAX[u1][2] + dpMAX[u2][1]) + 1;
        dpMAX[v][1] = max(dpMAX[u1][0] + dpMAX[u2][2], dpMAX[u1][2] + dpMAX[u2][0]);
        dpMAX[v][2] = max(dpMAX[u1][1] + dpMAX[u2][0], dpMAX[u1][0] + dpMAX[u2][1]);

        dpMIN[v][0] = min(dpMIN[u1][1] + dpMIN[u2][2], dpMIN[u1][2] + dpMIN[u2][1]) + 1;
        dpMIN[v][1] = min(dpMIN[u1][0] + dpMIN[u2][2], dpMIN[u1][2] + dpMIN[u2][0]);
        dpMIN[v][2] = min(dpMIN[u1][1] + dpMIN[u2][0], dpMIN[u1][0] + dpMIN[u2][1]);
    }

    //cout << v << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    build_a_tree(0);

    

    dfs(1);

    cout << max({dpMAX[1][0], dpMAX[1][1], dpMAX[1][2]}) << ' ' << min({dpMIN[1][0], dpMIN[1][1], dpMIN[1][2]});


}
