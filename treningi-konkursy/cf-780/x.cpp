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

        vector<int> wys;

        wys.push_back(0);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            if (a[i] == 0)
            {
                wys.push_back(i);
            }
        }

        wys.push_back(n+1);

        int res = -1;

        int L = -1, R = -1;

        for (int j = 0; j < wys.size()-1; j++)
        {
            if (wys[j+1] - wys[j] == 1 || wys[j+1] - wys[j] == 2  && a[wys[j]+1] < 0)
            {
                if (res < 0)
                {
                    res = 0;

                    L = n; R = 0;
                }
                continue;
            }

            int ilII = 0, ilMin = 0;

            for (int i = wys[j] + 1; i < wys[j+1]; i++)
            {
                if (a[i] < 0)
                    ilMin++;
                if (a[i] == -2 || a[i] == 2)
                    ilII++;
            }

            

            if (ilMin%2 == 0)
            {
                if (ilII > res)
                {
                    res = ilII;

                    L = wys[j];
                    R = n-wys[j+1];
                }
                continue;
            }

            int l = 0;

            for (int i = wys[j]+1; i < wys[j+1]; i++)
            {
                if (a[i] == -2 || a[i] == 2)
                    l++;

                if (a[i] < 0)
                {
                    //cout << ilII - l << ' ';

                    if (ilII - l > res)
                    {
                        res = ilII - l;

                        L = i;
                        R = n-wys[j+1];
                    }
                    break;
                }
            }

            l = 0;

            for (int i = wys[j+1]-1; i > wys[j]; i--)
            {
                if (a[i] == -2 || a[i] == 2)
                    l++;

                if (a[i] < 0)
                {
                    //cout << ilII - l << ' ';

                    if (ilII - l > res)
                    {
                        //cout << n-wys[j+1] << ' ';

                        res = ilII - l;

                        L = wys[j];
                        R = n-i+1;
                        
                        
                    }
                    break;
                }
            }

        }

        cout << max(L, 0) << ' ' << max(R, 0) << '\n';

        
    }
}