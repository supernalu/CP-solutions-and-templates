#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2010;

int t, n;

int a[MAXN];

int b[MAXN][MAXN];

int main()
{
    cin >> t;

    for (int w = 0; w < t; w++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        //sort(a + 1, a + n + 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                b[i][j] = a[i] ^ a[j];
                cout << b[i][j] << ' ';
            }  
            cout << endl; 
        }
    }
}