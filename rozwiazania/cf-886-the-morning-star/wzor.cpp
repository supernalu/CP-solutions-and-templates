#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n;

pair<long long, long long> point[MAXN];

pair<long long, long long> rotate(pair<long long, long long> a)
{
    return {a.first - a.second, a.first + a.second};
}

long long count()
{
    long long res = 0, tmp = 1; 
    sort(point + 1, point + n + 1);

    for (int i = 2; i <= n; i++)
    {
        if (point[i].first == point[i-1].first)
            tmp++;
        else
        {
            res += tmp*(tmp-1);
            tmp = 1;
        }
    }
    res += tmp*(tmp-1);
    for (int i = 1; i <= n; i++)
        point[i] = rotate(point[i]);    
    return res;
}


long long solve()
{
    int k = 4; long long res = 0;
    while (k--)
        res += count(); 
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            long long a, b; cin >> a >> b;
            point[i] = {a, b};
        }

        cout << solve() << '\n';
    }   
}