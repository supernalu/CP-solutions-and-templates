#include <bits/stdc++.h>

using namespace std;

int n, p;

int bits(int k)
{
    int res = 0;

    for (int i = 30; i >= 0; i--)
    {
        int h = (1 << i);

        if (k >= h)
        {
            //cout << k << ' ';

            k-=h;

            res++;
        }
    }

    return res;
}

int main()
{
    cin >> n >> p;

    int num = n;

    int res = -1;

    for (int i = 1; i <= 30; i++)
    {
        num -= p;

        if (num <= 0)
            continue;

        if (bits(num) <= i && i <= num)
        {
            res = i;
            break;
        }
    }

    cout << res;
}