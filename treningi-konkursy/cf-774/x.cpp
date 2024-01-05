#include<bits/stdc++.h>

using namespace std;

constexpr long long MAXN = 1e12 + 10;

int t;

long long n;

vector<long long> fac;

vector<long long> powe;
/*
map<long long, int> dp;

int solve(int a)
{
    //cout << a << ' ';

    if (a == 0)
        return 0;
    if (dp[a] != 0)
        return dp[a];

    int it1, it2;

    for (int i = 39; i >= 0; i--)
    {
        if (powe[i] <= a)
        {
            it1 = i;
            break;
        }
    }
    for (int i = 14; i >= 0; i--)
    {
        if (fac[i] <= a)
        {
            it2 = i;
            break;
        }

    }

    //cout << powe[it1] << ' ' << fac[it2] << endl;

    return dp[a] = min(solve(a - powe[it1]), solve(a - fac[it2])) + 1;
}
*/



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    fac.push_back(1);

    powe.push_back(1);


    for (int i = 1; i <= 100; i++)
    {
        fac.push_back(i*fac.back());

        //cout << fac.back() << ' ';

        if (i*fac.back() > MAXN)
            break;
    }

    long long sum = 1;

    for (int i = 1; i <= 100; i++)
    {
        powe.push_back(2*powe.back());

        sum += powe.back();

        if (sum > MAXN)
            //cout << i << endl;

        if (2*powe.back() > MAXN)
            break;
    }

    //cout << fac.size() << ' ' << powe.size() << endl;

    while (t--)
    {  
        cin >> n;

        //cout << solve(n) << '\n';

        vector<bool> used1(15, 0); vector<bool> used2(40, 0);

        int res = 0;

        while (n != 0)
        {
            int it1, it2;

            for (int i = 39; i >= 0; i--)
            {
                if (powe[i] <= n && used2[i] == 0)
                {
                    it1 = i;
                    break;
                }
            }
            for (int i = 14; i >= 0; i--)
            {
                if (fac[i] <= n && used1[i] == 0)
                {
                    it2 = i;
                    break;
                }

            }

            n = min(n - fac[it2], n - powe[it1]);

            if (n - fac[it2] < n - powe[it1])
            {
                used1[it2] = 1;
            }
            else
            {
                used2[it1] = 1;
            }
        
            res++;
        }

        cout << res << '\n';
    }

    
}