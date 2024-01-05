#include <bits/stdc++.h>
using namespace std;
int t, s, d, k;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int Ca = 1; Ca <= t; Ca++)
    {
        cout << "Case #" << Ca << ": "; 
        cin >> s >> d >> k;
        if (2*(s+d) > k && s+2*d >= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}