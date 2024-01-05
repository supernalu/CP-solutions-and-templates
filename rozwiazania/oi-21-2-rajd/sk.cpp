#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;

    cout << n << '-' << m << '/';

    while (m--)
    {
        int a, b;

        cin >> a >> b;

        cout << a << '-' << b << '/';
    }

    cout << " 1";
}