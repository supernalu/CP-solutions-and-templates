#include <bits/stdc++.h>


constexpr int MAXN = 1e6 + 10;

using namespace std;

int n;

int a[MAXN];

//int dp[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int Y = n+1;

    int res = n + Y;

    if (n == 1)
    {
        cout << "3 1";

        return 0;
    }

    cout << res << ' ';

    int r = n;

    long long il = 0;

    int old_Y = Y;

    int old_il = 0;

    for (int l = 0; l <= r; l++)
    {
        il++;        

        cout << l << ' ' << r << endl;

        while(a[r] <= Y/2 and l < r)
        {
            r--;
            Y++;
            il++;

            cout << l << ' ' << r << endl;
        }

        if (Y != old_Y)
            il--;


        //cout << il << ' ';

        if (a[l+1] - old_Y > Y )
            break;
        else
        {
            int q = max(a[l+1] - old_Y, 0);

            old_Y -= q;

            il = il + Y - old_Y;
        }

        //cout << il << endl;
    }

    cout << il;









         


    






    
}