#include <bits/stdc++.h>

using namespace std;

int n;

int a;

int main()
{
    cin >> n;

    if (n == 1)
    {
        cin >> a;

        for (int i = 0; i <= 30; i++)
        {
            if ((1 << i) > a)
            {
                cout << 2*i + 1;

                return 0;
            }
        }
    }
}