#include <bits/stdc++.h>

using namespace std;

long long n, x, y;

int main()
{
    cin >> n >> x >> y;

    if (x - n + 1 > (y - n + 1)*(y - n + 1) or y < n)
        cout << -1;
    else
    {
        cout << y - n + 1 << '\n';
        for (int i = 1; i < n; i++)
        {
            cout << "1\n";
        }
    }   
}