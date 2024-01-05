#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        long long a, b, x;
        bool res = 0;
        cin >> a >> b >> x;
        if (x > max(a, b))
        {
            cout << "NO\n";
        }
        else
        {
            long long c = __gcd(a, b), d = __gcd(a, x), e = __gcd(b, x);
            if ((c%d == 0 || d%c == 0) && (e%c == 0 || c%e == 0))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
}