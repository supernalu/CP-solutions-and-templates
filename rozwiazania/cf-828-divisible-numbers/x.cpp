#include <bits/stdc++.h>

using namespace std;
int t;
bool poss(long long k, long long a, long long c, long long b, long long d)
{
    int tmp = a*b/k;
    if (tmp == a)
        tmp = 2*a;
    if (k + a <= c && tmp  <= d )
    {
        cout << k + a << ' ' << tmp << '\n';
        return 1;
    }
    else
        return 0;
}
void findMaxGcd(long long a, long long c, long long b, long long d)
{
    long long maxi = 0;
    bool done = 0;
    for (long long i = 1; i*i <= a; i++)
    {
        if (a%i)
            continue;
        if (poss(a/i, a, c, b, d))
        {
            done = 1;
            break;
        }   
        else if (poss(i, a, c, b, d))
        {
            done = 1;
            break;
        }    
    }
    if (!done)
    {
        cout << "-1 -1\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        long long a, b, c, d;

        cin >> a >> b >> c >> d;

        findMaxGcd(a, c, b, d);
    }

}