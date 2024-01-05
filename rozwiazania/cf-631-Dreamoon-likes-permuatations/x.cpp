#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n, p[MAXN]; 
vector<int> wys[MAXN];
bool done[MAXN];
int vis[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            wys[i].clear();
            vis[i] = 0;
            done[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            wys[p[i]].push_back(i);
        }

        bool res = 1;
        int mini = 2;

        for (int i = 1; i <= n; i++)
        {
            mini = min(mini, (int)wys[i].size());
            if (wys[i].size() > mini)
                res = 0;
        }

        for (int i = 1 ; i <= n; i++)
        {
            if (done[p[i]])
                continue;
            if (wys[p[i]].size() > 2)
                res = 0;
            else if (wys[p[i]].size() == 2)
            {
                done[p[i]] = 1;
                sort(wys[p[i]].begin(), wys[p[i]].begin());
                vis[wys[p[i]][0]] = 1;
                vis[wys[p[i]][1]] = 2;
            }
        }
        if (!res)
        {
            cout << "0\n";
            continue;
        }

        bool zero = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
                zero = 1;
        }

        if (zero == 0)
        {
            int pointOfNoReturn = 0;
            bool poss = 1;

            for (int i = 1; i <= n; i++)
            {
                if (vis[i] == 2 && pointOfNoReturn == 0)
                pointOfNoReturn = i;

                if (pointOfNoReturn && vis[i] != 2)
                    poss = 0;
            }
            if (!poss)
            {
                cout << "0\n";
                continue;
            }


            cout << "1\n";

            cout << n/2 << ' ' << n/2 << '\n';
            continue;
       
        }

        int il = 0;
        int pointOfNoReturn = 0;
        vector<int> odt;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 2 && pointOfNoReturn == 0)
                pointOfNoReturn = i;

            if (pointOfNoReturn && vis[i] != 2)
                res = 0;
        }
        if (res)
        {
            il++;
            odt.push_back(pointOfNoReturn);
        }
        pointOfNoReturn = 0; res = 1;


        for (int i = n; i > 0; i--)
        {
            if (vis[i] == 1 && pointOfNoReturn == 0)
                pointOfNoReturn = i+1;

            if (pointOfNoReturn && vis[i] != 1)
                res = 0;
        }
        if (res)
        {
            il++;
            odt.push_back(pointOfNoReturn);
        }
        cout << il << '\n';
        for (auto i : odt)
            cout << i-1 << ' ' << n-i+1 << '\n';
            
        /*
        int change = 0;
        vis[0] = 1; vis[n+1] = 2;
        for (int i = 1; i<= n; i++)
        {
            if (vis[i-1] == vis[i+1] && vis[i] == 0 && vis[i-1] != 0)
            {
                if (change != 0 && change != vis[i])
                    res = 0;

                change = vis[i];
            }
        }

        if (!res)
        {
            cout << "0\n";
            continue;
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
                vis[i] = change;
        }
        for (int i = 1; i <= n; i++)
            cout << vis[i] << ' ';
        cout << '\n';

        vector<pair<int,int>> odt;
        for (int i = 1; i < n; i++)
        {
            if (vis[i] != vis[i+1])
                odt.push_back({i, i+1});      
        }
        cout << odt.size() << '\n';
        for (auto u : odt)
            cout << u.first << ' ' << u.second << '\n';
        */
    }
}