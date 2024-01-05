#include <bits/stdc++.h>

using namespace std;

int x[3], y[3], a[3];

bool cmp(int b, int c)
{
    return x[b] < x[c];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];

        a[i] = i;
    }

    sort(a, a + 3, cmp);

    int res = 0;

    if (x[a[2]] - x[a[0]] > 0)
        res++;

    if (y[a[0]] != y[a[1]])
        res++;

    if (y[a[2]] != y[a[1]])
        res++;

    cout << res << '\n';

    if (x[a[2]] - x[a[0]] > 0)
        cout << x[a[0]] << ' ' << y[a[1]] << ' ' << x[a[2]] << ' ' << y[a[1]] << '\n';

    if (y[a[0]] != y[a[1]])
        cout << x[a[0]] << ' ' << y[a[0]] << ' ' << x[a[0]] <<  ' ' << y[a[1]] << '\n';

    if (y[a[2]] != y[a[1]])
        cout << x[a[2]] << ' ' << y[a[2]] << ' ' << x[a[2]] << ' ' <<  y[a[1]] << '\n';



    
}