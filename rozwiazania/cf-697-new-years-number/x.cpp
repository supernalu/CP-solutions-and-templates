#include <bits/stdc++.h>

using namespace std;

int t;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int il = 0;

        while (n >= 2020)
        {
            n -= 2020;

            il++;
        }


        if (il < n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }

        
    }

}