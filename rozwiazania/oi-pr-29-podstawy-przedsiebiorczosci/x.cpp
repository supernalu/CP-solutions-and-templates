#include <bits/stdc++.h>

using namespace std;

int n, m;

long long k;

constexpr int MAXN = 1e6 + 10;

constexpr long long INF = 1e18 + 10;

unsigned long long b[MAXN];

long long binsearch(long long k, long long Q)
{
    long long res = INF;

    unsigned long long L = 0, R = Q + 10;

    while (L <= R)
    {
        long long mid = (L+R)/2;

        long long sum = 0;

        for (int i = 1; i <= m; i++)
        {
            sum += (mid/b[i]);
        }

        if (sum >= k)
        {
            res = min(res, mid);

            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }

    return res;
}

int main()
{
    cin >> n >> m >> k;

    if (n == 1)
    {
        int a;

        cin >> a;   

        unsigned long long mini = INF;    

        for (int i = 1; i <= m; i++)
        {
            int c;

            cin >> c >> b[i];

            mini = min(b[i], mini);
        }

        cout << binsearch(k, mini*k);

    }
}