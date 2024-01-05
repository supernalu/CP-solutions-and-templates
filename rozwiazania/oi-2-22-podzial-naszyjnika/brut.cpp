#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e6 + 10;

int n, k;

int a[MAXN];

int il_kol[MAXN];

int res, min_res = 1e9 + 10;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        il_kol[a[i]]++;
    }

    for (int i = 0; i < n-1; i++)
    {
        set<int> s;

        vector<int> il(k+1, 0);

        for (int j = i; j < n; j++)
        {
            il[a[j]]++;

            if (il[a[j]] == 1)
            {
                s.insert(a[j]);
            }
            if (il[a[j]] == il_kol[a[j]])
            {
                s.erase(a[j]);
            }

            if (s.empty())
            {
                res++;

                int q = j;

                if (j < i)
                    q += n;

                

                int dl = q - i + 1;

                min_res = min(abs(n - 2*dl), min_res);

                //cout << i << ' ' << j << endl;

            }
        }
    }

    cout << res-1 << ' ' << min_res;
}