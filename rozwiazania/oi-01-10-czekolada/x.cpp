#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<pair<int, bool>> a;

int il[2];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n-1; i++)
    {
        int b;

        cin >> b;

        a.push_back({b, 0});
    }

    for (int i = 1; i <= m-1; i++)
    {
        int b;

        cin >> b;

        a.push_back({b, 1});
    }

    sort(a.begin(), a.end());

    long long res = 0;

    for (int i = a.size()-1; i >= 0; i--)
    {
        res += a[i].first*(il[(a[i].second + 1)%2]+1);

        il[a[i].second]++;
    }

    cout << res;

    
}