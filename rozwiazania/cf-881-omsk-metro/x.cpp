#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n, act = 1;
int maxiPref[MAXN], miniPref[MAXN], pref[MAXN], maxiDP[MAXN], miniDP[MAXN];


void addVertice(int v, int x)
{
    act++;
    pref[act] = pref[v] + x;
    miniPref[act] = min(miniPref[v], pref[act]);
    maxiPref[act] = max(maxiPref[v], pref[act]);
    miniDP[act] = min(miniDP[v], pref[act]-maxiPref[act]);
    maxiDP[act] = max(maxiDP[v], pref[act]-miniPref[act]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    maxiPref[1] = 1; miniPref[1] = 0; pref[1] = 1; maxiDP[1] = 1; miniDP[1] = 0;
    cin >> t;

    while (t--)
    {
        act = 1;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            char type; cin >> type;

            if (type == '+')
            {
                int v, x; cin >> v >> x;
                addVertice(v, x);
            }
            else
            {
                int u, v, k; cin >> u >> v >> k;
                if (miniDP[v] <= k && k <= maxiDP[v])
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}