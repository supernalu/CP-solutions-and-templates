#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair <int, int>> x;

int res, max_res;



int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;

        cin >> a >> b;

        x.push_back({a, 1});
        x.push_back({b,-1});
    }

    sort(x.begin(), x.end());

    for (auto i: x)
    {
        res += i.second;

        if (res > max_res)
            max_res = res;               
    }
    cout << max_res;

}