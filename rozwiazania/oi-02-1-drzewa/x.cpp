#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2600;

int n;

int a[MAXN];

bool res = 0;
vector<int> adj[MAXN*3];
int parent[MAXN*3];

int maxi = 1;
int act = 1;

string bomba;

void dfs(int v, int layer)
{
    //cout << parent[v] << ' ' <<  v << ' ' << layer << ' ' << act << '\n';

    bomba += '(';

    if (act > n || layer > a[act])
    {
        //cout << "l\n";

        res = 0;

        return;
    }
    if(layer == a[act])
    {
        //cout << "k\n";
        bomba += ')';

        act++;
        if (act == n+1)
        {
            res = 1;
        }

        return;
    }
    
    maxi++;
    parent[maxi] = v;

    dfs(maxi, layer+1);

    maxi++;
    parent[maxi] = v;
    dfs(maxi, layer+1);

    bomba += ')';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    parent[1] = 0;

    dfs(1, 0);

    //cout << k;

    if (res)
    {
        //cout << "YES";

        cout << 0 << ' ';

        int k = 2; 

        while (parent[k] != 0)
        {
            cout << parent[k] << ' ';
            k++;
        }
        cout << '\n';

        cout << bomba << '\n';
    }
    else
        cout << "NIE\n";
    


}