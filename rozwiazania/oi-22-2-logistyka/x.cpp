#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

long long x[MAXN];

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        char type;

        cin >> type;

        if (type == 'U')
        {
            long long a, b;

            cin >> a >> b;

            x[a] = b;
        }
        else
        {
            long long a, b;

            cin >> a >> b;

            long long sum = 0;

            for (int i = 1; i <= n; i++)
            {
                sum += min(b, x[i]);
            }

            if (sum >= a*b) 
                cout << "TAK\n";
            else
                cout << "NIE\n";          
        }
    }
}