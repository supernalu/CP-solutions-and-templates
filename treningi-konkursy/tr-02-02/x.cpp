#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e3+10;

int t, n, m;
vector<int> a[MAXN], b[MAXN];
vector<int> aCopy[MAXN], bCopy[MAXN];




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;


        for (int i = 1; i <= m; i++)
        {
            aCopy[i].assign(n+1, 0);
            bCopy[i].assign(n+1, 0);
        }

        for (int i = 1; i <= n; i++)
        {
            a[i].assign(m+1, 0);
            for (int j = 1; j <= m; j++)
            {
                int tmp; cin >> tmp;
                a[i][j] = tmp;
                aCopy[j][i] = tmp;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            b[i].assign(m+1, 0);
            for (int j = 1; j <= m; j++)
            {
                int tmp; cin >> tmp;
                b[i][j] = tmp;
                bCopy[j][i] = tmp;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            sort(a[i].begin(), a[i].end());
            sort(b[i].begin(), b[i].end());

        }
        for (int i = 1; i <= m; i++)
        {
            sort(aCopy[i].begin(), aCopy[i].end());
            sort(bCopy[i].begin(), bCopy[i].end());    
        }
        sort(a + 1, a + n + 1); sort(b + 1, b + n +1);
        sort(aCopy + 1, aCopy + m + 1); sort(bCopy + 1, bCopy + m + 1);

        bool poss = 1; 

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == b[i][j])
                    continue;
                poss = 0;
                break;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (aCopy[i][j] == bCopy[i][j])
                    continue;
                poss = 0;
                break;
            }
        }

        if (poss)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}