#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e4 + 10;

int n; 
int x[MAXN];

int maxres;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)    
        cin >> x[i];
    

    
    /*
    for (int i = 0; i <= n; i++)
        cout << x[i] << ' ';
    cout << endl;
    */

    for (int i = 1; i < n; i++)
    {
        int r1 = 0, r2 = 0;
        for (int j = i; j < n; j++)
        {
            r1 += x[j];
        }
        for (int j = 1; j < i; j++)
        {
            r2 += x[j];
        }
        r2 += x[n];
        //cout << r1 << ' ' << r2 << endl;

        int res = min(r1, r2);
        maxres = max(res,maxres);

        for (int j = n-1; j > i; j--)
        {
            r1 -= x[j];
            r2 += x[j];
            int res = min(r1, r2);
            maxres = max(res,maxres);
        }
    }
    
    cout << maxres;


}