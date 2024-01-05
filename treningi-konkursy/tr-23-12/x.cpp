#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 20;

int n, W;

int t[MAXN], w[MAXN];

int a[MAXN][MAXN];



int solve(int v)
{
    int res = 1e9 + 10;

    if (v == n+1)
    {
        /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        */
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            int maxi = 0;
            for (int j = 0; j < n; j++)
            {   
                if (a[i][j] == -1)
                    break;
                maxi = max(t[a[i][j]], maxi);
            }
            sum += maxi;
        }
        //cout << sum << '\n';
        return sum;
    }
    int big_id = n;
    
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == -1)
        {
            big_id = i;
            break;
        }

        int sum = 0;
        int id = n;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
            {
                id = j;
                break;
            }
            sum += w[a[i][j]];
        }
        if (sum + w[v] <= W)
        {
            //cout << "bibi";

            a[i][id] = v;
            res = min(res, solve(v+1));
            a[i][id] = -1;
        }
    }
    a[big_id][0] = v;
    res = min(res, solve(v+1));
    a[big_id][0] = -1;

    return res;
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> W >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> w[i];
    }
    for (int i = 0; i < 20 ; i++)
    {
        for (int j = 0; j < 20; j++)
            a[i][j] = -1;
    }

    cout << solve(1);


}