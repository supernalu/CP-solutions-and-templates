#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int p, n;

int c[MAXN], d[MAXN];

int pref[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> p >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i-1] >> d[i];
    }

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + d[i];


    //for (int i = 0; i <= n; i++) {
        //cout << pref[i] << ' ';
    //}

    deque<pair<int, int>> mono_q;

    int j = 0;

    int res = 0;

    for (int i = 0; i <= pref[n]; i++)
    {
        if (i == pref[j])
        {
            while (!mono_q.empty() && mono_q.back().first >= c[j])
                mono_q.pop_back();

            mono_q.push_back({c[j], i});

            j++;
        }

        if (mono_q.front().second + p < i+1)
        {
            mono_q.pop_front();
        }

        res += mono_q.front().first;
    }

    cout << res;

}