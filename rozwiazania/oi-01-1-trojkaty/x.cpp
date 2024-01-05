#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e4+10;

int n;

pair<int, int> a[MAXN];

bool cmp(pair<int, int>b, pair<int, int> c)
{
    return b.first*c.second < b.second*c.first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string s;

        cin >> s;

        int b[2];

        b[0] = 0; b[1] = 0;

        int k = 0;

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '/')
            {
                k++;
                continue;
            }

            b[k] = 10*b[k] + s[j] - 48;

            //cout << b[k] << ' ';
        }

        //cout << b[0] << ' ' << b[1] << '\n';

        a[i] = {b[0], b[1]};
    }

    sort(a+1, a + n+1, cmp);

    /*
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].first << ' ' << a[i].second << '\n';
    }
    */
    
    if (a[1].first*a[2].second*a[n].second + a[2].first*a[1].second*a[n].second > a[n].first*a[2].second*a[1].second)
    {
        cout << "TAK\n";
    }
    else
    {
        cout << "NIE\n";
    }
    


}