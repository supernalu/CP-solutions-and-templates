#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int bits(int i)
{
    int res = 0;
    int k = (1 << 30);

    while (i > 0)
    {
        if (i >= k)
        {
            i -= k;
            res++;
        }

        k /= 2;
    }

    return res;
}


int a[MAXN];

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    int k = 0;
    int res;

    for (int i = 1; i <= 1e6; i++)
    {
        a[i] = bits(i);

        k += a[i];

        if (k >= n)
        {
            res = i;
            break;
        }
    }

    vector<int> bombiszon;
    for(int i = res; i >0; i--)
    {
        if (k-a[i] >= n)
        {
            k -= a[i];
            continue;
        }
        bombiszon.push_back(i);
    } 

    cout << bombiszon.size() << '\n';
    for (auto i : bombiszon)
        cout << i << ' ';
}