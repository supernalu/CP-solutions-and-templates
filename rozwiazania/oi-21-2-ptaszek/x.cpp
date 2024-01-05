#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

constexpr int LEAVES = 1 << 20;

constexpr int INF = 1e9;

int n;

int d[MAXN];

int q, k;

int dp[MAXN];

vector<int> x(2*LEAVES, 0);

vector<int> w(2*LEAVES, 0);

void update(int b, int c)
{
    int j = LEAVES + b;
 
    x[j] = c;

    w[j] = b;

 
    j /= 2;
 
    for (; j > 0; j /= 2)
    {
        if (x[2*j] == x[2*j+1])
        {
            if (d[w[2*j]] > d[w[2*j+1]])
                w[j] = w[2*j];
            else
                w[j] = w[2*j+1];
        }
        else if (x[2*j] < x[2*j+1])
        {
            w[j] = w[2*j];
        }
        else
        {
            w[j] = w[2*j+1];
        }

        x[j] = min(x[2*j], x[2*j + 1]);  
    }
}

int querry(int b, int c, int j)
{
    int res = INF;
 
    b += LEAVES;
    c += LEAVES;
 
    while (b <= c)
    {
        //cout << b << ' ' << c << endl;
 
        if (b == c)
        {
            if (d[w[b]] > d[j])
                res = min(x[b], res);
            else
                res = min(x[b] + 1, res);    
            break;
        }
 
        if (b%2 == 1)
        {
            if (d[w[b]] > d[j])
                res = min(x[b], res);
            else
                res = min(x[b] + 1, res);
            //cout << w[b] << ' ' << x[b] << endl;
            b++;
        }
        if (c%2 == 0)
        {
            if (d[w[c]] > d[j])
                res = min(x[c], res);
            else
                res = min(x[c] + 1, res);
            //cout << w[c] << ' ' << x[c] << endl;
            c--;
        }
                
        c /= 2;
        b /= 2;          
    }

    return res;
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    cin >> q;

    while (q--)
    {
        cin >> k;

        for (int i = 1; i <= n; i++)       
            dp[i] = INF;

        dp[1] = 0;

        update(1, 0);

        //cout << 0 << " ";

        for (int i = 2; i <= n; i++)
        {
            dp[i] = querry(max(1, i - k), i-1, i);

            update(i, dp[i]);

            //cout << dp[i] << ' ';

        }

        /*
        for (int i = 1; i < 2*LEAVES; i++)
            cout << w[i] << ' ';
        cout << endl;
        */

        cout << dp[n] << '\n';
    }

}
