#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t;

int n;

bool cmp(int b, int c)
{
    return b > c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> il(n+1, 0);

        il[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int b;

            cin >> b;

            il[b]++;
        }

        sort(il.begin(), il.end(), cmp);

        int k;

        for (int i = 0; i <= n; i++)
        {
            if (il[i] == 0)
            {
                k = i;
                break;
            }
        }

        int res = k;

        int sum = 0;

        bool odd = 0;

        for (int i = 0; i < k; i++)
        {

            il[i] = max(il[i] - k + i, 0);

            //sum += il[i];
        }

        sort(il.begin(), il.end(), cmp);

        for (int i = 0; i < k; i++)
        {
            if (il[i] == 0)
                break;

            odd = 0;

            //cout << il[i]/2 << ' ';
            
            k += il[i]/2;

            if (il[i]%2)
                odd = 1;
        }

        if (odd)
            k++;

        cout << k << '\n';

        //cout << sum << ' ';

        /*

        while (sum > 0)
        {
            res++;

            sum = sum - k - 1;
        }
        */

        //cout << res << '\n';
    }
}