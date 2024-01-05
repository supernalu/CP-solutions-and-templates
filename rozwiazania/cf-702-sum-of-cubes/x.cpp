#include <bits/stdc++.h>

using namespace std;

int t;

long long n;

int binSearch(long long a)
{
    long long res = -1;

    long long L = 1, R = sqrt(n);

    while (L <= R)
    {
        long long mid = (L+R)/2;

        if (a*a*a + mid*mid*mid == n)
        {
            res = mid;

            break;
        }
        if (a*a*a + mid*mid*mid < n)
        {
            L = mid + 1;
        }
        else if (a*a*a + mid*mid*mid > n)
        {
            R = mid -1;
        }
    }

    return res;
}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        bool poss = 0;

        for (long long i = 1; i*i*i <= n; i++)
        {
            //cout << binSearch(i) << ' ';

            if (binSearch(i) != -1)
            {
                poss = 1;
            }
        }

        if (poss)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}