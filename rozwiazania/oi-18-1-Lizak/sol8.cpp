#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

string s;

int t[MAXN];

int t_pref[MAXN];

pair<int,int> res[2*MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
            t[i+1] = 1;
        else
            t[i+1] = 2;     
    }

    for (int i = 1; i <= n; i++)
    {
        t_pref[i] = t_pref[i-1] + t[i];
    }

    int L = 1, R = n;

    res[t_pref[n]] = {1, n};

    while (L < R)
    {
        if (t[L] == t[R])
        {
            R--;
            res[t_pref[R] - t_pref[L-1]] = {L, R};
        }
        else 
        {
            res[t_pref[R-1] - t_pref[L-1]] =  {L, R-1};
            res[t_pref[R] - t_pref[L]] =  {L + 1, R};
            res[t_pref[R-1] - t_pref[L]] =  {L + 1, R-1};
            if(t[L] == 2)
                L++;
            else
                R--;
        
        }
    }

    for (int i = 0; i < m; i++)
    {
        int k;

        cin >> k;

        if(res[k].first != 0 )  cout << res[k].first << ' ' << res[k].second << endl;
        else cout << "NIE" << endl;
    }











}