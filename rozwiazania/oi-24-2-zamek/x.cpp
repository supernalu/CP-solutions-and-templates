#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int w, h, n, m;

struct rec 
{
    int up;
    int down;
    int left;
    int right;
    bool id;
};

rec komnaty[MAXN];

map<long long, vector<int>> g_up, g_down, g_left, g_right;

set<long long> x, y;

bool cmp_y (int a, int b)
{
    return komnaty[a].right < komnaty[b].left;
}


bool cmp_x (int a, int b)
{
    return komnaty[a].up < komnaty[b].down;
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> w >> h >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        komnaty[i].down = min(b, d);
        komnaty[i].up = max(b, d);

        komnaty[i].left = min(a, c);
        komnaty[i].right = max(a, c);

        komnaty[i].id = 1;

        g_up[komnaty[i].up].push_back(i);
        g_down[komnaty[i].down].push_back(i);
        g_right[komnaty[i].right].push_back(i);
        g_left[komnaty[i].left].push_back(i);

        x.insert(a);
        x.insert(c);
        
        y.insert(b);
        y.insert(d);

        //cout << i << ". " << komnaty[i].down << ' ' << komnaty[i].up << ' ' << komnaty[i].left << ' ' << komnaty[i].right << endl;

    }

    for (auto itr = y.begin(); itr != y.end(); itr++)
    {
        sort(g_up[*itr].begin(), g_up[*itr].end(), cmp_y);
        sort(g_down[*itr].begin(), g_down[*itr].end(), cmp_y);

        //cout << *itr << ": \n";

        /*
        for (auto u : g_up[*itr])
            cout << u << ' '; 
        cout << endl;
        */
    }

    for (auto itr = x.begin(); itr != x.end(); itr++)
    {
        sort(g_right[*itr].begin(), g_right[*itr].end(), cmp_x);
        sort(g_left[*itr].begin(), g_left[*itr].end(), cmp_x);
    }







    //usuwanie złych komnat

    for (int i = 1; i <= m; i++)
    {
        int a, b;

        cin >> a >> b;
    }


}