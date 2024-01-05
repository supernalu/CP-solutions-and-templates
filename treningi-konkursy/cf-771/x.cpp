#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t;

int n;

int a[MAXN];

//int pref[MAXN];

int wys[MAXN];



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            wys[a[i]] = i;
        }

        vector<bool>done(MAXN, 0);

       
        /*
        for (int i = n; i > 0; i--)
        {
            pref[i] = min(pref[i+1], a[i]);
        }
        */

        int mini = n+1;

        for (int i = n; i > 0; i--)
        {
            if(done[wys[i]] == 0)
            {
                if (i < mini)
                    res++;
                
                for (int j = wys[i]; j <= n && done[j] == 0; j++)
                {
                    if (done[j])
                    {
                        break;
                    }

                    done[j] = 1;

                    mini = min(mini, a[j]);

                }
            }

        }

        cout << res << '\n';

        



        

        


    }
}