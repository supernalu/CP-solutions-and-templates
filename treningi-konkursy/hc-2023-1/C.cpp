#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 4e6 + 10;
int t, n, q;
char s[MAXN];
int change[MAXN];
void Swap(int k)
{
    for (int i = k; i <= n; i+=k)
    {
        if (s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int Case = 1; Case <= t; Case++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            change[i] = 0;
        cin >> s+1;
        cin >> q;
        while (q--)
        {
            int tmp; cin >> tmp;
            change[tmp] = (change[tmp]+1)%2;
        }
        for (int i = 1; i <= n; i++)
        {
            if (change[i] == 0)
                continue;
            Swap(i);
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '1')
            {
                res++;
                Swap(i);
            }
        }
        cout << "Case #" << Case << ": " << res << '\n';
    }
}