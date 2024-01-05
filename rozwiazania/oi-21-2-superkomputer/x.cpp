#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, q;

int queries[MAXN];

vector<int> adj[MAXN];

bool cmp(int a, int b)
{
    if (adj[a].size() == adj[b].size())
    {
        return a < b;
    }

    return adj[a].size() > adj[b].size();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= q; i++)
    {
        cin >> queries[i];
    }

    for (int i = 2; i <= n; i++)
    {
        int a;

        cin >> a;

        adj[a].push_back(i);
    }
    


    for (int j = 1; j <= q; j++)
    {
        int qu = queries[j];

        set<int, decltype(cmp)*> s(cmp);

        int il = 0;

        int res = 0;

        s.insert(1);

        while (il < n)
        {
            res++;

            vector<int> tmp;

            for (int i = 1; i <= qu; i++)
            {
                if (s.empty())
                    break;

                for (auto i : adj[*(s.begin())])
                {
                    tmp.push_back(i);
                }

                il++;

                s.erase(s.begin());

                

            }
            for (auto i : tmp)
                    s.insert(i);

            

        }

        cout << res << ' ';
    }
}