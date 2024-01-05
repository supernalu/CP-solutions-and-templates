#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e3 + 10;

int mat[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;

    cin >> n >> k;

    int res = 1e9 + 1;



    for (int i = 1; i <= n; i++)
    {
        

        for (int j = 1; j <= i; j++)
        {
            int a;
            cin >> a;
            
            if(i == 1)
                mat[i][i] = 1;      
            else
            mat[i][j] = mat[i-1][j-1]+mat[i-1][j]-mat[i-2][j-1]+1;

            //cout << mat[i][j]<< ' ';

            if (mat[i][j] <= k && res > a)
                res = a;
        }
    }

    cout << res;
}