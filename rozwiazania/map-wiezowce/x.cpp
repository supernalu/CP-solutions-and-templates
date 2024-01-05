#include <bits/stdc++.h>

constexpr int MAXN = 1e6 + 10;
constexpr int LEAVES = 1<<20;
constexpr int INI = 0;
constexpr int INF = 1e9 + 7;

using namespace std;

int n, q;

pair<int,int> a[MAXN];

vector<int> x(2*LEAVES, 0);

struct question
{
    int a;

    int b;

    int c;

    int ID;
};

question w[MAXN];

bool cmp(question o, question p)
{
    return o.c < p.c;
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;

        a[i].second = i;
    } 

    sort (a + 1, a + n + 1);

    vector<int> odp(q + 3);

    for (int i = 1; i <= q; i++)
    {
        cin >> w[i].a >> w[i].b >> w[i].c;

        w[i].ID = i;
    }

    sort (w + 1, w + q + 1, cmp);

    int j = 1;

    for (int u = 1; u <= q; u++)
    {
        while (a[j].first <= w[u].c && j <= n)
        {
            int i = a[j].second + LEAVES;

            x[i] = 1;

            i /= 2;

            for (; i >= 1; i /= 2)
                x[i] = x[2*i] + x[2*i + 1];

            j++;
        }

        int b = w[u].a + LEAVES, c = w[u].b + LEAVES;

        int res = 0;

        while ( b <= c)
        {
            if (b == c)
            {
                res += x[b];
                break;
            }
            if (b%2 == 1)
            {
                res += x[b];
                b++;
            }
            if (c%2 == 0)
            {
                res += x[c];
                c--;
            }

            b /= 2;
            c /= 2;

        }
        
        odp[w[u].ID] = res;
    }

    for (int i = 1; i <= q; i++)
        cout << odp[i] << '\n';
}