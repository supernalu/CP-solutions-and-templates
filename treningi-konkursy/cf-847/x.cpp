#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5+10;

int t, n;

map<int, int> m;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        bool bits[33];

        bool res = 1;
        int a = 0, b = 0;

        for (int i = 0; i < 30; i++)
        {
            if (n & (1 << i))
            {
                bits[i] = 1;
                b += (1 << i);
            }
            else
                bits[i] = 0;
           //cout << bits[i] << ' ';
            
        }
        if ((2*n - b)%2)
            res = 0;
        //cout << 2*n-b << ' ';
        
        int x = (2*n-b)/2;
        //cout << x << ' ';

        for (int i = 1; i <= 32; i++)
        {
            if ((x & (1 << i) && bits[i] == 1))
                res = 0;
            else
                continue;
        }

        if (res)
            cout << x << ' ' << b+x << '\n';
        else
         cout << -1 << '\n';



    }
}