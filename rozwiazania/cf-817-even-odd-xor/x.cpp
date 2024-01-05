#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k = 0;

    for (int i = 1; i <= 25; i++)
    {
        k = k xor i;

        cout << k << ' ';
    }

    cout << '\n';

    k = 0;

    for (int i = 1; i <= 25; i+=2)
    {
        k = k xor i;

        cout << k << ' ';
    }

    cout << '\n';

    k = 0;

    for (int i = 0; i <= 25; i+=2)
    {
        k = k xor i;

        cout << k << ' ';
    }

}