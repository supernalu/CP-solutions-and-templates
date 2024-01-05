#include <bits/stdc++.h>

using namespace std;

int n, m;
int mask , bestMask;
bool edge[30][30];
vector<pair<int, int>> swaps;
int il[30][2];
map<int, int> ma;

void getMask(int m)
{
    for (int i = 0; i < n; i++)
    {
        if (m & (1 << i))
            cout << 1;
        else
            cout << 0;
    }
}

void getNextMask(int &m)
{
    int c, r, nextMask; 
    c = m & -m;
    r = mask + c;
    nextMask = r | ((r^m) >> 2)/c;

    swaps.clear();
    int k = (r & -r) >> 1;
    swaps.emplace_back(r & -r, k);

    int tmp = 1; //cout << c << ' ' << k << '\n';
    while (k != c)
    {
        //cout << (m & k) << ' ' << (nextMask & k) <<  '\n';
        k = k >> 1;
        if ((m & k) != 0 && (nextMask & k) == 0)
            swaps.emplace_back(k, tmp);
        tmp *=2;
    }
    m = nextMask;
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    mask = (1 << (n/2)) - 1;

    int tmp = 1;
    for (int i = 0; i < n; i++)
    {
        ma[tmp] = i;
        tmp*=2;
    }

    while (m--)
    {
        int a, b; cin >> a >> b;

        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    int tmp1 = 0;
    //getMask(mask);
    //cout << '\n';
    for (int v = 1; v <= n; v++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (!edge[v][u])
                continue;

            if (((mask & (1 << (v-1))) !=  0 && (mask & (1 << (u-1))) == 0) || ((mask & (1 << (u-1))) !=  0 && (mask & (1 << (v-1))) == 0))
            {    
                tmp1++;
                il[v][1]++;   
            }
            else
                il[v][0]++;
        }
    }

    int res = tmp1;
    bestMask = mask;
    do
    {
        getNextMask(mask);

        //getMask(mask);
        //cout << ' ';
        for (auto i : swaps)
        {
            int k = ma[i.first], l = ma[i.second];

            //cout << k << ' ' << l << '\n';
            tmp1 = tmp1 - il[k+1][1] - il[l+1][1];

            swap(il[k+1][0],il[k+1][1]);
            swap(il[l+1][0],il[l+1][1]);

            if (edge[k+1][l+1])
            {
                il[k+1][1]++;
                il[l+1][1]++;
                il[k+1][0]--;
                il[l+1][0]--;
            }     
            tmp1 = tmp1 + il[k+1][1] + il[l+1][1]; 
        }
        //cout << '\n';
        
        //cout << tmp1 << '\n';
    
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