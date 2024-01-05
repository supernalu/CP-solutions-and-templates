#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e2 + 5;

int n;

vector <int> adj[MAXN];

int ring[MAXN];

pair <int, int> lol[MAXN][MAXN];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        pair <int, int> pom;        
        pom.first = c;
        pom.second = 0;
        lol[a][b] = pom;

        pom.second = 1;
        lol[b][a] = pom;

            
    }
    int sum[2];
    sum[0] = 0;
    sum[1] = 0;
    int v = adj[1][1];
    int parent = 1;
    ring[1] = 1;
    int j = 1;
    ring[n+1] = 1;

    while (v != 1)
    {
        for (auto u: adj[v])
        {
            if (u != parent)
            {
                j++;
                ring[j] = v;
                parent = v;
                v = u; break;
            }
        }
    }
    /*
    for (int i = 1; i <= n + 1; i++)
    {
        cout << ring[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
           cout << lol[i][k].first << ' ';
        cout << endl;
    }
    cout << endl;
    */
    

    for (int i = 2; i <= n+1; i++)
    {

        int a = ring[i-1];
        int b = ring[i];

        //cout << lol[a][b].second << ' ' << lol[a][b].first << endl;

        sum[lol[a][b].second] += lol[a][b].first;        
    }
    cout  <<  min(sum[0], sum[1]);

}