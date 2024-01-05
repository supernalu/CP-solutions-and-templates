#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;;

int n, m, d;

int res[MAXN];
set<pair<int, int>> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> d;

    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;

        s.insert({a, i});
    }

    int minuta = -d;
    int dni = 1;

    while (s.size())
    {
        minuta += d;
        auto it = s.lower_bound({minuta, 0});
        if (it == s.end())
        {
            minuta = -d;
            dni++;
            continue;
        }
        pair<int, int>tmp = *it;
        s.erase(it);
        int czas = tmp.first, id = tmp.second;
        minuta = czas+1;
        res[id] = dni;
    }

    cout << dni << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
    //looooooooooooooooool

}