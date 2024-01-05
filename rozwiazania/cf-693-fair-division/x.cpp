#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t;

int n;

int a[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int sum = 0;

        a[1] = 0; a[2] = 0;

        for (int i = 0; i < n; i++)
        {
            int b;

            cin >> b;

            a[b]++;

            sum += b;
        }

        sum /= 2;

        if (a[1]%2 == 1 or sum%2 == 1 && a[1] == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
        
    }
}