#include <bits/stdc++.h>

using namespace std;

int n;

int minn = 1e9 + 10, maxx = - 1e9 - 10;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        minn = min(minn, a);

        maxx = max(maxx, a);
    }

    cout << maxx - minn;
}