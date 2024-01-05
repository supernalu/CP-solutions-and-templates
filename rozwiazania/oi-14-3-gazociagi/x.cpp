#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

struct pkt
{
    int x; 
    int y;

    int id;
};

bool cmp (pkt a, pkt b)
{
    if (a.x == b.x)
    {}
}

pkt sb[MAXN];

bool used[MAXN];

pair<int, int> wh[MAXN];

int res = 0;

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;

        cin >> a >> b;

        sb[i] = {a, b, i};    

        res = res + b - a;    
    }
    for (int i = n+1; i <= 2*n; i++)
    {
        int a, b;

        cin >> a >> b;

        sb[i] = {a, b, i};    

        res = res + a - b;    
    }

    cout << res << '\n';



    for (int i = 1; i <= n; i++)
    {
        
    }

}