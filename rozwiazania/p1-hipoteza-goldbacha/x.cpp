#include <bits/stdc++.h>
using namespace std;
bool isPrime(int k)
{
    for (int i = 2; i*i <= k; i++)
    {
        if (k%i)
            continue;
        return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n/2; i++)
    {
        if (isPrime(i) && isPrime(n-i))
            cout << i << ' ' << n-i << '\n';
    }
}