#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e3 + 10;

int n, k;

int a[MAXN];



int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    int res = 1e9 + 10;

    int id_res = 0;
    

    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;

        
        for (int j = 1; j <= n;  j++)
        {          
            if (a[j] != a[i] + k*(j-i))        
                tmp++;  

            if (a[i] + k*(j-i) <= 0)
            {
                tmp += 1e9 + 10;
                break;
            }
              
        }

        if (tmp < res)
        {
            res = tmp;

            id_res = i;
        }
    }

    cout << res << endl;

    
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[id_res] + k*(i-id_res))
        {
            cout << "+ "  << i << ' ' << a[id_res] + k*(i-id_res) - a[i] << '\n';
        }
        else if (a[i] > a[id_res] + k*(i-id_res))
        {
            cout << "- " << i << ' ' <<  a[i] - a[id_res] - k*(i-id_res) << '\n';
        }
    }
}