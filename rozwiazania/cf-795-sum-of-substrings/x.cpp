#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;

int t, n, k;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> s;

        int firstZero = n;
        int LastZero = n;

        for (int i = 1; i <= n; i++)
        {
            if (s[i-1] == '1')
            {
                firstZero = i-1;
                break;
            }
        }
        for (int i = n-1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                LastZero = i;
                break;
            }
        }
        //cout << firstZero << ' ' << LastZero << ' ';

        bool done = 0;

        if (n-1-LastZero <= k && LastZero != n )
        {
            swap(s[n-1], s[LastZero]);
            k -= n-1-LastZero;
            done = 1;
        }

        if (!(LastZero == firstZero && done) && firstZero <= k && firstZero != n)
            swap(s[0], s[firstZero]);

        int res = 0;
        for (int i = 0; i < n-1; i++)
        {
            res += 10*(s[i]-'0') + s[i+1]-'0';
        }
        cout << res << '\n';
    }
}