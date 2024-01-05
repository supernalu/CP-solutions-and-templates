#include <bits/stdc++.h>

using namespace std;

int t, n;


int main()
{
    cin >> t;

    for (int w = 0; w < t; w++)
    {
        cin >> n;

        vector<int>a(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i]; 
        }

        sort(a.begin(), a.end());

        int l = 0;

        long long res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] != a[i-1])
                l = max(l-1, -1);


            l++;
            
            res += l;

            
        }

        cout << res << endl;
    }
}