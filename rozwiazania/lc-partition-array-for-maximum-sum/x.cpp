#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 510;

constexpr int INF = 1e9 + 10;

vector<int> arr(MAXN);

int k;

int n;

int dp[MAXN];

int main()
{
    cin >> n;

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
m
    for (int i = 0; i < n; i++)
    {
        //dp[i] = INF;
    }

    dp[0] = arr[0];
    int p = arr[0];
    for (int i = 1; i < k; i++)
    {  

        p = max(p, arr[i]);      

        dp[i] = p*(i+1);

        //cout << dp[i] << ' ';
    }

    //cout << endl;

    for (int i = k; i < n; i++)
    {
        
        for (int w = i-k+1; w <= i; w++)
        {
            int maxi = 0;
            for (int j = w; j <= i; j++)
            {
                maxi = max(arr[j], maxi);
            }      

            int len = i-w+1;
            dp[i] = max(dp[i], dp[w-1] + len*maxi);

            //cout << dp[i] << ' ';
        }

        //cout << endl;
    }

    cout << dp[n-1];

    

}