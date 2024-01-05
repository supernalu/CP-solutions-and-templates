#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

constexpr int MOD = 1e9 + 7;

int n, a, b, p, m;

string pattern;

string c;

int res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> a >> b >> p >> m;

    cin >> pattern;

    c.resize(n);

    for (int i = 0; i < n; i++)
    {
        if ((a*i + b)%n >= p)
        {
            c[i] = '1';
        }
        else
        {
            c[i] = '0';
        }
    }

    
    
    string s = '\0' + pattern + "#" + c;

    //cout << s;

    vector<int> prefsuf(n + m + 2, -1);
    int j = -1;

    for (int i = 1; i <= n + m + 1; ++i) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = prefsuf[j];
        }
        prefsuf[i] = ++j;
    }

    for (int i = 1; i <= n + m + 1; i++)
    {
        //cout << prefsuf[i] << ' ';

        if (prefsuf[i] == m)
            res++;
        
    }

    cout << res;


}