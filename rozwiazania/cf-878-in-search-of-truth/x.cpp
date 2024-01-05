#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

int wh[MAXN];

int main()
{
    for (int i = 0; i < MAXN; i++)
        wh[i] = -1;
    int act; cin >> act;
    wh[act] = 1;

    for (int i = 2; i <= 1000; i++)
    {
        cout << "+ 1\n";
        cout.flush();
        cin >> act;
        if (wh[act] != -1)
        {
            cout << "! " << i-1 << '\n';
            cout.flush();
            return 0;
        }
        wh[act] = i;
    }
    int res = 1000;
    //cout << "! " << -res << '\n';
    //cout.flush();
    //return 0;
    for (int i = 1; i <= 1000; i++)
    {
        cout << "+ 1000\n";
        cout.flush();
        cin >> act;
        res += 1000;
        if (wh[act] == -1)
        {
            continue;
        }
        res -= wh[act];
        cout << "! " << res << '\n';
        cout.flush();
        return 0;
    }
}