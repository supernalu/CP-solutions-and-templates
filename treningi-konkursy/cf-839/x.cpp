#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 5e5 + 10;

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

        int ile1 = 0, ile2 = 0, ileWS = 0;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] != i)
            {
                ile1++;
            }
            if (a[i] != n-i+1)
            {
                ile2++;
            }
            if (a[i] != n-i+1 && a[i] != i)
            {
                ileWS++;
            }
        }

        //cout << ile1 << ' ' << ile2 << ' ' << ileWS << '\n';

        if (ile1 <= ile2 - ileWS)
        {
            cout << "First\n";
        }
        else if (ile2 <= ile1 - ileWS-1)
        {
            cout << "Second\n";
        }
        else 
            cout << "Tie\n";

        
    }
}