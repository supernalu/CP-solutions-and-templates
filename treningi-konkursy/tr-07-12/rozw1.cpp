/*
Nastazja Lukoszek
Elektrownie i Fabryki [B] - Potyczki algorytmiczne 2020
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int LEAVES = 1<<18;
constexpr int MAXN = 5e5 + 10;

int n;
int a[MAXN];
int sumA[MAXN];
int dp[MAXN];
int id[MAXN];

bool cmp(int b, int c)
{
    if (sumA[b] == sumA[c])
        return b < c;

    return sumA[b] < sumA[c];
}


vector<int> MinimumRangeQueries(2*LEAVES, 1e9);

void update(int b, int c)
{
    b += LEAVES;
 
    MinimumRangeQueries[b] = c;
 
    b /= 2;
 
    for (; b >= 1; b /= 2)
        MinimumRangeQueries[b] = min(MinimumRangeQueries[2*b], MinimumRangeQueries[2*b+1]);
}
int minimum(int b, int c)
{
    b += LEAVES;
    c += LEAVES;
 
    int res = 1e9;
 
    while (b <= c)
    {
        if (b == c)
        {
            res = min(res, MinimumRangeQueries[b]);
            break;
        }
        if (b%2 == 1)
        {
            res = min(res, MinimumRangeQueries[b]);
            b++;
        }
        if (c%2 == 0)
        {
            res = min(res, MinimumRangeQueries[c]);
            c--;
        }
 
        b /= 2;
        c /= 2;
    }

    return res;
}






int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    sumA[0] = 0; dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sumA[i] = sumA[i-1] + a[i];
    }

    if (sumA[n] < 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i <= n; i++)
    {
        id[i] = i;
    }
    sort(id, id + n + 1, cmp);

    update(id[0], 0);
    for (int i = 1; i <= n; i++)
    {
        //cout << minimum(id[0], id[0]);

        dp[i] = minimum(0, id[i])+i-1;

        cout << dp[i] << ' ';

        update(id[i], dp[i]-i);

        

        /*
        for (int j = 0; j <= i; j++)
        {
            cout << minimum(0, id[j])+i+1 << ' ';
        }
        cout << '\n';
        */
    }

    cout << dp[n];
}