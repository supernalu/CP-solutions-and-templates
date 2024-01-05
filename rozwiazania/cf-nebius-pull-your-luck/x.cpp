#include <bits/stdc++.h>

using namespace std;
long long t, n, x, p;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> t;

    while (t--)
    {
        cin >> n >> x >> p;

        bool res = 0;

        for (long long i = 1; i <= min(p, 2*n+10); i++)
        {
            if ((2*x+(i*(i+1)))%(2*n) == 0)
            {
                res = 1;
                break;
            }
        }

        if (res)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}