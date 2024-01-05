#include <bits/stdc++.h>

using namespace std;

int t;

int n, k;

int a[12];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        k++;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        a[n+1] = 18;

        long long  tmp = 0, res = 0, nom = 1, nomII = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = a[i-1]; j < a[i]; j++)
            {
                nom *= 10;
            }

            for (int j = a[i]; j < a[i+1]; j++)
            {
                nomII *= 10;
            }

            //cout << nomII << ' ';

            res += min(k-tmp, nomII/nom - 1)*nom;

            tmp += min(k - tmp, nomII/nom - 1);

            //cout << tmp << ' ';
            
            if (tmp == k)
                break;          
        }

        cout << res << '\n';


    }
}