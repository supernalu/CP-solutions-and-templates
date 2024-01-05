#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 210;

int t, n;
int a[MAXN][10];
int many[10][10];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 6; j++)
                many[i][j] = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][1];
            many[a[i][1]][1]++;
        }
        
        
        
    }
}