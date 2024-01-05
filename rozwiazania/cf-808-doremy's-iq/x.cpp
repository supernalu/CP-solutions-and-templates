#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t, n, q;

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int>res;

        int k = 0;

        for (int i = n; i > 0; i--)
        {
            if (a[i] <= k)
            {
                res.push_back(1);

                continue;
            }


            if (k == q)
            {
                res.push_back(0);

                continue;
            }

            res.push_back(1);

            k++;
        }

        reverse(res.begin(), res.end());

        for (auto i : res)
            cout << i;
        cout << '\n';
     
    }
}
