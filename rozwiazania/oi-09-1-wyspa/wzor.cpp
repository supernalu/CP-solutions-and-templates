#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e4 + 10;

int n; 

int x[MAXN];
int r1, r2;
int maxres;
int maxk;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        if (x[i] > maxk)
            maxk = x[i];
    }
    
    
    for (int i = 1; i < n; i++)
        r1 += x[i];
    r2 = x[n];

    int L = 1, R = n;
    for (int i = 1; i <= 2*n; i++)
    {
        if (r1 > r2)
        {
            R--;
            if (R == 0)
                R = n;
            r1 -= x[R];
            r2 += x[R];
        }
        else if (r1 < r2)
        {
            L--;
            if (L == 0)
                L = n;
            r1 += x[L];
            r2 -= x[L];
        }
        else
        {
            cout << r1;
            return 0;
        }
        //cout << L << ' ' << R << endl;
        int res = min(r1, r2);
        maxres = max(res, maxres);                    
    }
    cout << maxres;

}