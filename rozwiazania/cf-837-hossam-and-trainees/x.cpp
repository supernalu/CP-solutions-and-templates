#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 1e5 + 10;

int t, n;
int a[MAXN];
vector<int> primes;
vector<bool> vis(MAXN, 0);

void sieve(int k)
{
    for (int i = 2; i <= k; i++)
    {
        if (vis[i])
            continue;
        primes.push_back(i);
        for (int j = i; j <= k; j += i)
            vis[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve(35000);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);

        bool res = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i+1])
                res = 1;
        }

        for (auto p : primes)
        {
            int il = 0;

            for (int i = 1; i <= n; i++)
            {
                if (!(a[i]%p))
                il++;
            }
            if (il >= 2)
            {
                res = 1;
                break;
            }
        }
        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}