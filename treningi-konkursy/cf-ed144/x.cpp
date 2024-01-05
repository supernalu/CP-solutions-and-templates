#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 10;
constexpr ll MOD = 998244353;

int t;
int n;

ll dpSize[MAXN];
ll dpCombi[MAXN][2];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dpSize[0] = 0;
    dpSize[1] = 1;

    for (int i = 1; i <= MAXN; i++)
    {
        if (i*2 <= MAXN)
        {
            dpSize[2*i] = max(dpSize[2*i], dpSize[i]+1);
        }
        if (i*3 <= MAXN)
        {
            dpSize[3*i] = max(dpSize[3*i], dpSize[i]+1);
        }

        dpSize[i] = max(dpSize[i-1], dpSize[i]);
    }

    dpCombi[0][0] = 0;
    dpCombi[1][0] = 1;

    for (int i = 1; i <= MAXN; i++)
    {
        if (i*2 <= MAXN)
        {
            dpSize[2*i]++;
        }
        if (i*3 <= MAXN)
        {
            dpSize[3*i]++;
        }

        dpSize[i] = max(dpSize[i-1], dpSize[i]);
    }    

    cin >> t;

    while (t--)
    {
        int l, r;

        cin >> l >> r;

        cout << dpSize[r]-dpSize[l-1] << ' ';
        
    }
}