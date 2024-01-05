#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

int n;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        bool res = 1;

        pair<int, int>a[MAXN];

        vector<vector<int>>il(MAXN);



        for (int i = 1; i <= n; i++)
        {
            cout << a[i].first << a[i].second;

            il[a[i].first].push_back(i);

            il[a[i].second].push_back(i);

            if (a[i].second < a[i].first)
                swap(a[i].first, a[i].second);

            if (a[i].first == a[i].second || il[a[i].first].size() > 2 || il[a[i].second].size() > 2)
            {
                res = 0;
                break;
            }
        }

        if (!res)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = 1; i <= n; i++)
        {
            if (il[i].size() == 2)
            {
                int c = il[i][0], b = il[i][1];

                if (a[c].first != i)
                {
                    c = a[c].first;
                }
                else
                {
                    c = a[c].second;
                }

                if (a[b].first != i)
                {
                    b = a[b].first;
                }
                else
                {
                    b = a[b].second;
                }

                if (b == c)
                    continue;

                
            }
        }



        



        
        
    }
}