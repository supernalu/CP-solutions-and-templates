#include <bits/stdc++.h>

using namespace std;

int t, n;
string x;
int il[26];
int ilP[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> x;

        int res = 0;
        if (n%2 == 1)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < 26; i++)
        {
            il[i] = 0;
            ilP[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            il[x[i] - 'a']++;
            if (il[x[i]-'a'] > n/2)
                res = -1;
        }
        if (res == -1)
        {
            cout << res << '\n';
            continue;
        }
        int maxi = 0;
        int g = 0;
        for (int i = 0; i < n/2; i++)
            if (x[i] == x[n-i-1])
            {
                ilP[x[i]-'a']++;
                g++;  
                maxi = max(maxi, ilP[x[i]-'a']);           
            }    
        res = max(maxi, (g+1)/2);
        cout << res << '\n';
    }
}