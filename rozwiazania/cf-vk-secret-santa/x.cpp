#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

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

        int res = 0;

        vector<bool> used(n+1, 0);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        set<int> s;

        for (int i = 1; i <= n; i++)
            s.insert(i);


        for (int i = 1; i <= n; i++)
        {
            s.erase(a[i]);
        } 

        vector<int> odt;

        for (int i = 1; i <= n; i++)
        {
            if(!used[a[i]])
            {
                res++;
                used[a[i]] = 1;

                odt.push_back(a[i]);
            }
            else
            {
                odt.push_back(*(s.begin()));
                s.erase(s.begin());
            }
        }

        cout << res << '\n';

        for (auto i : odt)
        {
            cout << i << ' ';        
        }
        cout << '\n';

        

        
    }
}