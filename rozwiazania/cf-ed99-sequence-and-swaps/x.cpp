#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 510;

int t;

int n, x;

int a[MAXN];

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> x;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        int wh[MAXN];

        



        a[n+1] = x;

        sort (a + 1, a + n + 2);



        for (int k = 1; k <= n; k++)
        {
            vector<int>tmp;

            for (int i = 1; i <= n; i++)
            {
                if (i != k)
                {
                    tmp.push_back(a[i]);
                }
            }
        }


    }
}