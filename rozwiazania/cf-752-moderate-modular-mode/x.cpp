#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int x, y;

        cin >> x >> y;

        if (y%x == 0)
        {
            cout << x << '\n';
        }
        else if (y < x)
        {
            cout << x+y << '\n';
        }
        else
        {
            cout << y-(y%x)/2 << '\n';        
        }

    }
}