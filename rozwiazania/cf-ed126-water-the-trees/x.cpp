#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

int t;

struct solution {

    int n;

    vector<int> a;

    vector<int> copy;

    long long  solve()
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            long long tmp;

            cin >> tmp;

            a.push_back(tmp);

            copy.push_back(tmp);
        }

        sort(a.begin(), a.end());

        sort(copy.begin(), copy.end());

        long long L = 0, R = 1e15 + 10;

        long long RES = 1e15  + 20;

        //cout << "DB";

        while (L <= R)
        {
            long long mid = (L+R)/2;

            for (int i = 1; i <= n; i++)
            {
                a[i-1] = copy[i-1];
            }

            long long il2 = mid/2, il1;

            if (mid%2)
                il1 = il2 + 1;
            else
                il1 = il2;

            for (int i = 0; i < n; i++)
            {
                long long b = a[n-1] - a[i];

                a[i] += 2*min(il2, b/2);

                il2 -= min(il2, b/2);       
            }  

            //cout << "DB";

            for (int i = 0; i < n; i++)
            {
                long long b = a[n-1] - a[i];

                a[i] += min(il1, b);

                il1 -= min(il1, b);       
            }  

            //cout << "DB";

            bool res = 1;

            for (auto i : a)
            {
                //cout << i << ' ';

                if (i != a[n-1])
                    res = 0;
            }

            if (res)
            {
                RES = min(RES, mid);

                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }

        L = 0; R = 1e15 + 10;

        long long RES2 = 1e15 + 20;

        while (L <= R)
        {
            long long mid = (L+R)/2;

            for (int i = 1; i <= n; i++)
            {
                a[i-1] = copy[i-1];
            }

            long long S = a[n-1] + 1;

            long long il2 = mid/2, il1;

            if (mid%2)
                il1 = il2 + 1;
            else
                il1 = il2;

            for (int i = 0; i < n; i++)
            {
                long long b = S - a[i];

                a[i] += 2*min(il2, b/2);

                il2 -= min(il2, b/2);       
            }  

            //cout << "DB";

            for (int i = 0; i < n; i++)
            {
                long long b = S - a[i];

                a[i] += min(il1, b);

                il1 -= min(il1, b);       
            }  

            //cout << "DB";

            bool res = 1;

            for (auto i : a)
            {
                //cout << i << ' ';

                if (i != S)
                    res = 0;
            }

            if (res)
            {
                RES2 = min(RES2, mid);

                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }

            //cout << RES2 << ' ';
        }

                

        return min(RES, RES2);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        solution a;

        cout << a.solve() << '\n';
    }
}