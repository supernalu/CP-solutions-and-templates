#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int n;

long long a[MAXN];

bool used[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        long long res = 1e9 + 10;
        int id;

        for (int j = 1; j <= n; j++)
        {
            if (used[j])
                continue;

            long long tmp = sum + a[j];  

            int taken = 0;

            for (int k = 1; k <= n; k++)
            {
                if (a[k] <= tmp)
                {
                    tmp -= a[k];
                    taken++;
                }      
            }

            if (taken == i)
            {
                res = min(res, a[j]);

                if (res == a[j])
                    id = j;

                //cout << res;
            }
        }

        sum += res;

        used[id] = 1;

        cout << sum << ' ';
    }


}