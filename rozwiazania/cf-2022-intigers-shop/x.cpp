#include <bits/stdc++.h>

using namespace std;

int t, n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int mini = 1e9 + 10, maxi = 0, price_mini = 1e9 + 10, price_maxi = 1e9 + 10;
        int bestL = 1e9 + 10, bestR = 0, price;

        for (int i = 1; i <= n; i++)
        {
            int a, b, c; 

            cin >> a >> b >> c;

            if (a < bestL || b > bestR || (c < price && a == bestL && b == bestR))
            {
                bestL = a;
                bestR = b;
                price = c;
            }

            if (a < mini || (price_mini > c && a == mini))
            {
                price_mini = c;
                
                mini = a;
            }
            if (b > maxi || (price_maxi > c && b == maxi ))
            {
                price_maxi = c;
                
                maxi = b;
            }

            

            if (mini == bestL && maxi == bestR)
                cout << min(price, price_maxi + price_mini) << '\n';
            else
                cout << price_maxi + price_mini << '\n';


            

            

        }
    }
}