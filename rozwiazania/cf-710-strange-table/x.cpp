#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        long double  a, b, c;

        cin >> a >> b >> c;

        long long column = ceil(c/a);

        long long row = (long long)c%(long long)a;

        if (row == 0)
            row = a;

        //cout << row << ' '<< column << ' ';

        cout << (long long)((row-1)*b + column) << endl;
    }
}