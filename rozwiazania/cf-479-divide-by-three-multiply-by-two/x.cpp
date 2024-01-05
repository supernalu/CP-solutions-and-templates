#include <bits/stdc++.h>

using namespace std;

int n;

long long a[110];

bool cmp(long long c, long long b)
{
    long long pow = 1;

    while (true)
    {
        if (c%pow == 0 && b%pow != 0)
        {
            return 1;
        }
        else if (b%pow == 0 && c%pow != 0)
        {
            return 0;
        }
        else if (c%pow != 0 && b%pow != 0)
        {
            pow = 1;

            while (true)
            {
                if (c%pow == 0 && b%pow != 0)
                {
                    return 0;
                }
                else if (b%pow == 0 && c%pow != 0)
                {
                    return 1;
                }
                //cout << pow << ' ';

                pow *= 2;
            }
        }

        //cout << pow << ' ';

        pow *= 3;
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort (a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }

}