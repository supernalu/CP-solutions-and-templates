#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 2e5 + 10;

int n, k;
ll a[MAXN];
map<ll, int> m;
ll res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[a[i]] = 0;
    }

    ll R = 0;
    int tmp = 0;
    for (ll L = 1; L <= n; L++)
    {
        while(tmp <= k && R <= n)
        {
            R++;
            m[a[R]]++;
            if (m[a[R]] == 1)
                tmp++; 
            
        }
        res += R-L;
        
        m[a[L]]--;
        if (m[a[L]] == 0)
            tmp--;
    }

    cout << res;


    
}