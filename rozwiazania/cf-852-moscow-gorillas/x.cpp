#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 10;

int n;
ll p[MAXN], q[MAXN];
int idP[MAXN], idQ[MAXN];
set<int> sP, sQ;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> q[i];

    for (int i = 1; i <= n; i++)
    {
        idP[p[i]] = i;
        idQ[q[i]] = i;
    }

    sP.insert(0);
    sP.insert(n+1);
    sQ.insert(0);
    sQ.insert(n+1);

    ll res =0;

    for (int i = 1; i <= n; i++)
    {
        auto itP = (sP.begin(), sP.end(), p[i]);

        ll upP = (itP)* - 1ll;
        --itP;
        ll downP = itP* + 1ll;

        auto itQ = (sQ.begin(), sQ.end(), q[i]);

        ll upQ = itQ* - 1ll;
        --itQ;
        ll downQ = itQ* + 1ll;

        ll up = min(upQ, upP);
        ll down = max(downQ, downP);
        res += (up-down)*(up-down+1)/2;
    }

    cout << res;



    
}