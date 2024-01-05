#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[30];
int mask, bestMask;

void getNextMask(int &m)
{
    int c, r, nextMask; 
    c = m & -m;
    r = mask + c;
    nextMask = r | ((r^m) >> 2)/c;

    m = nextMask;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    mask = (1 << (n/2))-1;

    while (m--)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = 1e9;
    do
    {
        getNextMask(mask);
        int tmp1 = 0;
        
        for (int v = 1; v <= n; v++)
        {
            for (auto u: adj[v])
            {
                if ((mask & (1 << (v-1))) != 0)
                    continue;

                if (((mask & (1 << (u-1))) !=  0 && (mask & (1 << (v-1))) == 0))
                {    
                    tmp1++;  
                }
            }
        }

        if (tmp1 < res)
        {
            res = tmp1;
            bestMask = mask;
        }
    } while(mask != (1 << n)-(1<<(n/2)));

    for (int i = 0; i < n; i++)
    {
        if (((bestMask & (1 << i)) != 0 &&  (bestMask & (1 << 0)) != 0) || ((bestMask & (1 << i)) == 0 &&  (bestMask & (1 << 0)) == 0))
            cout << i+1 << ' ';
    }
}