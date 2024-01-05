#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 3e5 + 10;



int n;
ll a[MAXN], b[MAXN];

bool cmp (int c, int d)
{
    if (b[c] == b[d])
        return c < d;
    return b[c] < b[d];
}

set<int, decltype(&cmp)> s(&cmp);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    ll il = 0;

    for (int i = 1; i <= n; i++)
    {
        il += a[i];

        if (il >= b[i])
        {
            s.insert(i);
            il -= b[i];
            continue;
        }
        
        if (s.empty())
            continue;

        int tmp = *(s.rbegin());
        if (b[i] < b[tmp])
        {
            s.erase(--s.end());
            s.insert(i);
            il += (b[tmp]-b[i]);
        }
    }

    vector<int>res;
    for (auto i : s)
        res.push_back(i);
    
    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto i : res)
        cout << i << ' ';
    

    
}