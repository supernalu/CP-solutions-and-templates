#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

int a[MAXN];

int dp[MAXN];

int maxi;

vector<bool> is_prime(MAXN, 1);

vector<int> divi[MAXN];

void sito(int m)
{

    for (int i = 2; i <= m; i++)
    {
        if (!is_prime[i])
            continue;

        divi[i].push_back(i);

        for (int j = 2*i; j <= m; j += i)
        {
            divi[j].push_back(i);
            is_prime[j] = 0;
        }
    } 
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        maxi = max(maxi, a[i]);
    }

    if (n == 1)
    {
        cout << 1;

        return 0;
    }

    sito(maxi);

    vector<int> best(MAXN, 0);



    for (int i = 1; i <= n; i++)
    {
        /*
        for (auto j : divi[a[i]])
        {  
            cout << j << ' ';
        }
        cout << endl;
        */

        for (auto j : divi[a[i]])
        { 
            //cout << best[j] << ' ';


            dp[i] = max(dp[i], best[j] + 1);    
        }
        //cout << endl;

        for (auto j : divi[a[i]])
        {  
            best[j] = dp[i]; 
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i]);

        //cout << dp[i] << ' ';
    }

    cout << res;




}