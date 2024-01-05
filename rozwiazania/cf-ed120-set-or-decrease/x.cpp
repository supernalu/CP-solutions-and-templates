#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

int n; 

long long k;

long long sum;

long long a[MAXN];

/*
long long solve()
{
    int L = 0, R = 2e9;

    long long res = 1e15 + 10;

    while (L <= R)
    {
        long long mid = (L+R)/2;
        long long act = mid;

        long long s = sum - mid;


        for (int i = n; i > 1; i--)
        {
            if (s <= k)
                break;
            
            s = s - a[i] + a[1]-mid;

            act++;

            if (s <= k)
                break;
        }

        

        if (act < res && s <= k)
        {
            //cout << res << ' ';

            res = act;
            R = mid - 1;
        }
        else
            L = mid+1;
    }

    return res;
}
*/

long long solve()
{
    long long L = 1, R = 1e15;

    long long res = 1e15 + 10;

    while (L <= R)
    {
        long long mid = (L+R)/2;
        bool good_enough = 0;

        long long s = sum - mid;
        long long mini = a[1] - mid;

        if (s <= k)
            good_enough = 1;

                
            



        for (int i = n; i > 1 && n - i + 1 <= mid; i--)
        {
            mini++;
            
            s = s - a[i] + mini + n-i+1;

            if (s <= k)
            {
                good_enough = 1;

                break;
            }
            
        }

        

        if (good_enough)
        {
            //cout << res << ' ';

            res = min(res, mid);
            R = mid - 1;
        }
        else
            L = mid+1;
    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

        while (t--)
        {
            cin >> n >> k;

            sum = 0ll;

            for (int i = 1; i <= n; i++)
            {
                cin >> a[i];
                
                sum += a[i];
            }

            if (sum <= k)
            {
                cout << "0\n";
                continue;
            }

            sort(a + 1, a + n + 1);

            cout << solve() << '\n';
            
        }
}