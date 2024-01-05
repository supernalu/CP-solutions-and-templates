#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;

int t, n;
int a[MAXN], b[MAXN];
int res[MAXN];

int solve(int a, int b, int r)
{

    int c = abs(a-b);

    a = b; b = c;

    if (a%3 == 0)
        return  r;
    else
        return  solve(a, b, (r+1)%3);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1;  i <= n; i++)
            cin >> b[i];


        int tmp = 3;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0 && b[i] == 0)
            {
                res[i] = 3;
                continue;
            }
            res[i] = solve(a[i], b[i], 1);
            tmp = res[i];
        }

        if (tmp == 3)
        {
            cout << "YES\n";
            continue;
        }

        bool yup = 1;
        for (int i = 1; i <= n; i++)
        {
            //cout << res[i] << ' ';
            if (res[i] == 3)
                continue;

            if (res[i] != tmp)
                yup = 0;
        }

        if (yup)
            cout << "YES\n";
        else
            cout << "NO\n";
        


        
    }
}