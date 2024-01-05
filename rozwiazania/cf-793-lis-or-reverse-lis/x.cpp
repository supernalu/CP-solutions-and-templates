#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

int n;

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            cout << "1\n";
            continue;
        }

        sort(a+1, a+n+1);

        vector<int>b;

        b.push_back(a[1]);
        b.push_back(a[2]);

        for (int i = 3; i<= n; i++)
        {
            if (a[i] == a[i-2])
                continue;
            b.push_back(a[i]);
        }

        b.push_back(1e9+10);

        int res = (b.size()-1)/2;

        for (int i = 0; i < b.size()-1; i++)
        {
            if (b[i]==b[i+1])
            {
                i++;
                continue;
            }

            int res1 = 0, res2 = 0;

            if (i%2 == 0)
            {
                res1 = i/2;
                res2 = i/2;
            }
            else
            {
                res1 = i/2+1;
                res2 = i/2;
            }

            if ((b.size()-i-2)%2 == 0)  
            {
                res1 += (b.size()-i-2)/2;
                res2 += (b.size()-i-2)/2;
            }
            else
            {
                res1 += (b.size()-i-2)/2;
                res2 += (b.size()-i-2)/2+1;
            }

            //cout << i << ' ' << b.size()-i-1 << ' ' << res1 << ' ' << res2;

            res = max(res, min(res1, res2)+1);
            
        }

        cout << res << '\n';





        


    }
}