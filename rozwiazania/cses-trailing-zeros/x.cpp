#include <bits/stdc++.h>

int n;

int main()
{
    std::cin >> n;

    long long res = 0;
    long long pow = 1;

    for (int i = 1; i <= 15; i++)
    {
        pow *= 5;

        res += n/pow;
    }

    std::cout << res;
}