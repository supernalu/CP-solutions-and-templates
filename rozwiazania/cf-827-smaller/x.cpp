#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int t, n;
ll il[3][30];

void init()
{
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 30; i++)
            il[j][i] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> t;

    while (t--)
    {
        init();
        il[1][0] = 1; il[2][0] = 1;
        cin >> n;

        while (n--)
        {
            ll w, k;
            string s;
            cin >> w >> k >> s;

            for (auto c : s)
            {
                il[w][c-'a'] += k;
            }

           

            int mini = -1;
            int maxi = -1;
            
            for (char c = 'z'; c >= 'a'; c--)
            {
                if (il[1][c-'a'] > 0)
                    mini = c-'a';
            }
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (il[2][c-'a'] > 0)
                    maxi = c-'a';
            }

            if (mini < maxi)
                cout << "YES\n";
            else if (mini > maxi || (mini == maxi && il[1][mini] > il[2][mini]))
                cout << "NO\n";
            else
            {
                bool musi = 0;

                for (char c = 'z'; c > mini+'a'; c--)
                {
                    if (il[1][c-'a'] > 0)
                        musi = 1;
                }

                if (musi)
                {
                    cout << "NO\n";
                    continue;
                }

                for (char c = 'a'; c < mini+'a'; c++)
                {
                    if (il[2][c-'a'] > 0)
                        musi = 1;
                }

                if (il[1][mini] == il[2][mini] && musi || il[1][mini] < il[2][mini])
                {
                    cout << "YES\n";
                }
                else
                    cout << "NO\n";


            }

        }
    
    }
}
