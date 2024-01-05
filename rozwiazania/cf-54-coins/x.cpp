#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;

    int j = 2;

    cout << n << ' ';

    while (n != 1)
    {
        while (n%j != 0)
        {
            j++;
        }
        n /= j;

        cout << n << ' ';
    }
}