#include <bits/stdc++.h>

using namespace std;



int t;

long long n, x, res;

long long a;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> x >> res;

        long long sum = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> a;

            sum += a;
        }

        if ((sum + x + res)%2 == 0)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }

    }
}