#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n;

pair <long double, long double>  a[MAXN];

int id[MAXN];

bool cmp(int b, int c)
{
    return a[c].first*a[b].second < a[b].first*a[c].second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;

        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp);

    for (int i = 1; i <= n; i++)
        cout << id[i] << '\n'; 
}