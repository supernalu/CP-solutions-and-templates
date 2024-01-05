#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        long long a, b;

        cin >> a >> b;

        if (a == b)
        {
            cout << a*(a-1)+1 << '\n';
        }
        else if (a > b)
        {
            cout << a*(a-1)+1 - (long long)pow(-1, (a+1)%2)*(a-b) << '\n';
        }
        else
        {
            swap(a, b);

            //cout << a*(a-1)+1 << ' ';

            cout << a*(a-1)+1 + (long long)pow(-1, (a+1)%2)*(a-b) << '\n';
        }



    }
}