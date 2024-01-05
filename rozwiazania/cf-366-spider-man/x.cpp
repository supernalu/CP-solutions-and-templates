#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;

    int sum = 0, a;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;

        a--;

        sum += a;

        if (sum%2)
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }
}