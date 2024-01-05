#include <bits/stdc++.h>

using namespace std;

int t, n;

int main()
{
    cin >> t;

    for (int w = 0; w < t; w++)
    {
        cin >> n;

        int l = 1;

        while(l*2 <= n)
        {
            l *= 2;
        }

        cout << l - 1 << endl;


    }
}