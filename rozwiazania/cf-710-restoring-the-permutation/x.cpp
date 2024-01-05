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

        int perm[MAXN];

        vector<bool>used(MAXN, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            if(a[i] != a[i-1])
            {
                perm[i] = a[i];

                used[a[i]] = 1;

                
            }
            else
            {
                perm[i] = 0;
            }
        }

        int j = 1;

        for (int i = 1; i <= n; i++)
        {
            if (perm[i] == 0)
            {
                while (used[j])
                    j++;

                cout << j << ' ';

                j++;
            }
            else
                cout << perm[i] << ' ';
        }
        cout << endl;


        set<int> s;

        for (int i = 1; i <= n; i++)
        {
            if(!used[i])
                s.insert(i);
        }

        for (int i = 1; i <= n; i++)
        {
            if (perm[i] == 0)
            {

                auto it = lower_bound(s.begin(), s.end(), a[i]);

                it--;
                
                cout << *it << ' ';


                s.erase(it);     
            }
            else
                cout << perm[i] << ' ';
        }
        cout << endl;
    }
}