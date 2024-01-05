#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 410;

int t, n;

string a[MAXN];

int main()
{
    cin >> t;

    for (int w = 0; w < t; w++)
    {
        cin >> n;

        pair<int, int> x[3];

        int it = 1;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == '*')
                {
                    x[it].first = i;
                    x[it].second = j;
                    it++;

                    
                } 
            }
        }

        if (x[1].first == x[2].first)
        {
            a[(x[1].first+1)%n][x[1].second] = '*';
            a[(x[1].first+1)%n][x[2].second] = '*';
        }
        else if (x[1].second == x[2].second)
        {
            a[x[1].first][(x[1].second+1)%n] = '*';
            a[x[2].first][(x[2].second+1)%n] = '*';
        }
        else
        {
            a[x[1].first][x[2].second] = '*';
            a[x[2].first][x[1].second] = '*';
        }

        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
            cout << endl;
        }

    }
}