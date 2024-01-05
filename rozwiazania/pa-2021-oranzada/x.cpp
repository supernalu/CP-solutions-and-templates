#include <bits/stdc++.h>

constexpr int MAXN = 5e5 + 10;

using namespace std;

int n, k;

int a[MAXN];

bool ma[MAXN];

int wys[MAXN];


int main()
{
    cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> k;

    int il = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (!ma[a[i]])
        {
            ma[a[i]] = 1;
            il++;
        }    
    }

    if (il < k)
    {
        cout << -1;

        return 0;
    }

    long long q = k;
    long long w = 0;

    long long res = 0;

    for (int i = 1; i <= k; i++)
    {
        wys[a[i]]++;
    }

    

    
    for (int i = k; i > 0; i--)
    {
        if (wys[a[i]] > 1)
        {
            res += q - i;
            q--;
            w++;
            wys[a[i]]--;
        }

    }

    int i = k+1;

    while (w > 0)
    {
        if (wys[a[i]] == 0)
        {
            w--;
            res += i - k + w;            

            wys[a[i]]++;
        }
        i++;
    }

    cout << res;
}