#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int il = 0;
        while (n--)
        {
            int a; cin >> a;
            if (a%2)
                il++;
        }
        if (n == 1 || il%2)
            cout << "NO\n";
        else
            cout << "YES\n";
        
    }
}