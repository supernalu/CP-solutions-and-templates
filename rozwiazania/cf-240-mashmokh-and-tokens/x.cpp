#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, a, b;

int binSearch(long long R)
{
    long long L = 0;

    long long res = (R*a)/b;

    long long id = R;

    while (L <= R)
    {
        long long mid = (L+R)/2;

        if ((mid*a)/b == res)
        {
            id = min (id, mid);

            R = mid - 1;
        }
        if ((mid*a)/b < res)
        {
            L = mid + 1;
        }
    }

    return id;

}

int main()
{

    
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        int x;

        cin >> x;

        cout << x - binSearch(x) << ' ';
    }


}