#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 8e3 + 10;

int n, m;

vector<int> adj[MAXN];

int color[MAXN];

vector<int> setColor[3];

bool is_good = true;

void dfs(int v, int clr)
{
    color[v] = clr;
    setColor[clr].push_back(v);

    for (auto u: adj[v])
    {
        if (color[u] != 0)
        {
            if (color[u] == clr) 
            {
                is_good = false;
            }
            continue;
        }        
        dfs(u, ((clr) % 2 + 1));
        
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    while(m--)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i < 2*n; i+=2)
    {
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }

    for (int i = 1; i <= 2*n; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;            
            dfs(i, 1);
            //cout << endl;
        }
    }

    //cout << is_good;

    //cout << setColor[1].size();

    if (!is_good || setColor[1].size() != n)
    {
        cout << "NIE";
        return 0;
    }

    sort(setColor[1].begin(), setColor[1].end());

    int k = 0;

    for (auto i : setColor[1])
    {
        //cout << k << ' ';

        k++;
        if ((i+1)/2 != k)
        {
            cout << "NIE";

            return 0;
        }
    }

    for (auto i : setColor[1])
        cout << i << '\n';

    


}