#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1 << 15;

constexpr int MAXK = 110;

constexpr int INI = 0;

vector<vector<int>> treeMax(MAXK, vector<int> (2*MAXN, INI));


void update(int id, int k, int u)
{
    id += MAXN; 

    treeMax[u][id] = k;

    id /= 2;

    for (; id >= 1; id /=2)
        treeMax[u][id] = max(treeMax[u][id*2], treeMax[u][id*2 + 1]);
}

int rangeMax(int left, int right, int u)
{
    int res = 0;

    while (left <=  right)
    {
        if (left  == right)
        {
            res = max(treeMax[u][left], res);
            break;
        }
        if (left % 2 == 1)
        {
            res = max(treeMax[u][left], res);

            left++;
        }
        if (right % 2 == 0)
        {
            res = max(treeMax[u][right], res);

            right++;
        }

        left /= 2;

        right /= 2;
    }

    return res;
}

int n, k, q;


int main()
{
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;

            cin >> a;

            update(j, a, i);
        }
    }

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int type, a, b, c;

        cin >> type >> a >> b >> c;

        if (type == 1)
        {
            update(a, b, c);
        }
        else
        {
            cout << rangeMax(a, b, c) << '\n';
        }
    }
}