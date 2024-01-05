#include <bits/stdc++.h>

using namespace std;

long long n, k, c;

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
  
    cin >> n >> k >> c;

    if (n <= 1000000)
    {
        int j = 0;

        for (long long i = 1; i <= 2*n; i++)
        {
            if (__gcd(i, n) == 1)
            {
                j++;

                if (j >= k)
                {
                    cout << i << ' ';
                }

                if (j >= k + c-1)
                {
                    break;
                }
            }
        }
    }
}