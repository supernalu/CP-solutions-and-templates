#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3010;

int n;

struct rectangle{
    int left;
    int right;
    int down;
    int up;

    pair<int, int> res = {0, 0};
};

rectangle a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].left >> a[i].down >> a[i].right >> a[i].up;
    }

    for (int i = 1; i <= n; i++)
    {
        int odl = MAXN+10, id = 0;

        for (int j = 1; j <= n; j++)
        {
           if (a[j].res.first != 0 || a[j].left > i || a[j].right < i)
            continue;

            if (odl > a[j].right-i)
            {
                odl = a[j].right-i;
                id = j;
            }
        }

        if (id == 0)
        {
            cout << "NIE";
            return 0;
        }

        a[id].res.first = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int odl = MAXN+10, id;

        for (int j = 1; j <= n; j++)
        {
           if (a[j].res.second != 0 || a[j].down > i || a[j].up < i)
            continue;

            if (odl > a[j].up-i)
            {
                odl = a[j].up-i;
                id = j;
            }
        }

        if (id == 0)
        {
            cout << "NIE";
            return 0;
        }


        a[id].res.second = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i].res.first << ' ' << a[i].res.second << '\n';
    }
}