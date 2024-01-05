#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 10005;

int n, S;

int res[MAXN];

int sum;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> S;

    if (n == 1)
    {
        if (S == 0)
            cout << '0';
        else 
            cout << "NIE";
        return 0;
    }
    if (n == 2)
    {
        if (S == -1)        
            cout << "-1";
        else if (S == 1)
            cout << "1";
        else 
            cout << "NIE";
        return 0;
    }
    if (n == 3)
    {
        if (S == -3)
            cout << "0 -1 -2";
        else if (S == -1)
            cout << "0 -1 0";
        else if (S == 1)
            cout << "0 1 2";
        else if (S == 3)
            cout << "0 1 0";
        else
            cout << "NIE";
    }
    else 
    {        
        for (int i = 1; i <= n; i++)
        {
            res[i] = i-1;
            sum += i-1;
        }
        

        if (S % 2 == sum % 2 && S >= -sum && S <= sum)
        {
            if (S >= 0)
            {
                while(sum > S)
                {
                    int max = -1e9;
                    int wh_max;

                    for (int i = 1; i <= n; i++)
                    {
                        if (res[i] >= max)
                        {
                            wh_max = i;
                            max = res[i];
                        }
                    }
                    
                    res[wh_max] -= 2;
                    sum -= 2;
                }

                for (int i = 1; i <= n; i++)
                {
                    cout << res[i] << ' ';
                }
            }
            else
            {
                for (int i = 1; i <= n; i++)
                    res[i] = -res[i];
                
                sum = -sum;

                while(sum < S)
                {
                    int max = 1e9;
                    int wh_max;

                    for (int i = 1; i <= n; i++)
                    {
                        if (res[i] < max)
                        {
                            wh_max = i;
                            max = res[i];
                        }
                    }
                    
                    res[wh_max] += 2;
                    sum += 2;
                }

                for (int i = 1; i <= n; i++)
                {
                    cout << res[i] << ' ';
                }
            }
        }
        else
        {
            cout << "NIE";
        }
        
    }
}