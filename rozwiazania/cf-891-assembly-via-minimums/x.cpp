#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int t, n;
int a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n; 
        for (int i = 1; i <= (n*(n-1))/2; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + (n*(n-1))/2 + 1);
        int last, act = 1, ch = n;
        for (int i = 1; i < n; i++)
        {
            cout << a[act] << ' ';
            last = a[act];
            ch--;
            act += ch;
        }
        cout << last << '\n';
    }
}