#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

constexpr int INF = 1e9;

int n;

int d[MAXN];

int q, k;

int dp[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    cin >> q;

    for (int w = 0; w < q; w++)
    {
        cin >> k;

        for (int i = 1; i <= n; i++)       
            dp[i] = INF;

        dp[1] = 0;

        deque<int> mon;

        mon.push_back(1);

        for (int i = 2; i <= n; i++)
        {
           dp[i] = dp[mon.front()];

           if (d[mon.front()] >= d[i])           
               dp[i]++;   

            while(dp[mon.back()] > dp[i])
            {
                mon.pop_back();                  
                if (mon.size() == 0)
                    goto siup;
            }       

            while(dp[mon.back()] == dp[i] && d[mon.back()] < d[i])
            {
                mon.pop_back();               
                if (mon.size() == 0)
                        break;
            }

            siup:
            mon.push_back(i);           

            if (i - mon.front() > k)
                mon.pop_front();
        }

        cout << dp[n] << endl;
    }
}