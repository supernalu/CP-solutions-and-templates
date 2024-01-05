#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

int n;

int a[MAXN];
int id[MAXN];


int res[MAXN];

bool cmp (int c, int b)
{
    return a[c] < a[b];
}


int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp);

    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        j = max(a[id[i]], j);

        res[id[i]] = j;

        j++;
    }

    for (int i = 1; i <=  n; i++)
    {
        cout << res[i] << ' ';
    }


}