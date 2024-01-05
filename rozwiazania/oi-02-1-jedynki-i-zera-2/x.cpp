#include <bits/stdc++.h>

constexpr int MAXN = 1e6 + 10;

using namespace std;



int n;

int parent[MAXN];

char parChange[MAXN];

int dist[MAXN];

void bfs(int n)
{
    dist[1] = 1;

    parent[1] = 1;

    parChange[1] = '1';

    queue<int> q;

    q.push(1);

    while (!q.empty())
    {
        int v = q.front();

        //cout << v << ' ';

        q.pop();   

        if (dist[(v*10)%n] == 0)
        {
            dist[(v*10)%n] = dist[v]+1;

            parent[(v*10)%n] = v;

            parChange[(v*10)%n] = '0';

            q.push((v*10)%n);
        }
        if (dist[(v*10+1)%n] == 0)
        {
            dist[(v*10+1)%n] = dist[v]+1;

            parent[(v*10+1)%n] = v;

            parChange[(v*10+1)%n] = '1';

            q.push((v*10+1)%n);
        }

    }
}

void solve(int n)
{
    bfs(n);

    if (dist[0] == 0)
    {
        cout << "BRAK\n";

        return;
    }

    int i = 0;

    vector<char>res;

    while (parent[i] != i)
    {
        res.push_back(parChange[i]);

        i = parent[i];
    }

    res.push_back('1');

    reverse(res.begin(), res.end());

    for (auto i : res)
        cout << i;

    cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //cout << "UwU";

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (n == 1)
        {
            cout << "1\n";

            continue;
        }

        for (int i = 0; i < n; i++)
        {
            dist[i] = 0;
        }

        solve(n);
  
    }
}

