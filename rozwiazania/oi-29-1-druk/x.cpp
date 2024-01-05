#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

int n, m;

char a[MAXN][MAXN];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];     
    
    if (n == 1)
    {
        int res = 0;
        vector<int> reso;

        for (int i = 1; i <= m; i++)
        {
            if (!(m%i))
            {
                for (int j = 1; j <= i; j++)
                {
                    for (int k = i; j + k <= m; k += i)
                    {
                        
                        if (a[1][j] != a[1][j + k])
                            goto wtf;
                        
                    }
                }
                res++;
                reso.push_back(i);
            }
            

            wtf:

            int x;
        }

        cout << res << '\n';

        for (auto i : reso)
            cout << i << ' ';
    }
    else if (n <= 3)
    {
        
    }

}