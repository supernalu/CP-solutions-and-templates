#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 60;

int t;

int n;

double a[MAXN];

int binSearch(double a, double b)
{
    int L = 0, R = 10;

    int res = 11;

    while (L <= R)
    {
        int mid = (L+R)/2;

        int pow = 1;

        for (int i = 0; i < mid; i++)
        {
            pow *= 2;
        }


        if (b > 2*a*pow)
        {
            L = mid + 1;
        }
        else if (b <= 2*pow*a)
        {
            res = min(res, mid);

            R = mid - 1;
        }  
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        int res = 0;

        for (int i = 1; i < n; i++)
        {
            double maxi = max(a[i], a[i+1]);
            double mini = min(a[i], a[i+1]);

            res += binSearch(mini, maxi);
        }

        cout << res << endl;

    }


}