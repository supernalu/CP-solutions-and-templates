#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 200005;

int n, m, k;

int a[MAXN], b[MAXN];
int res;

//!Do poprawy!

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    sort(a + 1, a + n+1);
    sort(b + 1, b + m+1);
    
    /*
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    for (int i = 1; i <= m; i++)    
        cout << b[i] << ' ';
    cout << endl;  
    */
    
    int R = 1;  
    for (int L = 1; L <= m; L++)
    {
        //cout << L << ' ' << R << ' ';
        while(a[R] < b[L] - k && R <= n)
        {
            R++;
        }
        if (a[R] <= b[L] + k && a[R] >= b[L] - k)
        {
            //cout << 'r';
            res++;
            R++;
        } 
        //cout << endl;       
    }
    cout << res;
      

}