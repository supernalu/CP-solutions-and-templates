#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n;
int a[MAXN];
vector<int> dividors[MAXN];
int il[MAXN];
void getDiv(int k)
{
    for (int i = 1; i*i <= k; i++)
    {
        if (k%i != 0)
            continue;
        dividors[k].push_back(i);
        if (i*i != k)
            dividors[k].push_back(k/i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i < MAXN; i++)
        getDiv(i);
    cin >> t;
    while (t--)
    {
        cin >> n; 
        for (int i = 1; i <= n; i++)
            il[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] > n)
                continue;
            il[a[i]]++;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            
            int tmp = 0;
            for (auto d : dividors[i])
            {
                tmp += il[d];            
            }
            //cout << tmp << ' ';
            res = max(res, tmp);
        }
        cout << res << '\n';
        
    }
}