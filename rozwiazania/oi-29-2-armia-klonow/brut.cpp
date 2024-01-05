#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int solve(long long i, long long j, long long res)
{
    if (i > n)
        return res;

        if (i <= j)
        {
            return solve(i+j, j, res + b);
        }

    return min(solve(i,i, res + a), solve(i+j, j, res + b));
}


int main()
{
    cin >> n >> a >> b;

    cout << solve(1, 1, a);
}