#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, z;

pair<int, int> a[MAXN];
int id[MAXN];

bool cmp (int b, int c)
{
    if (a[b].first == a[c].first)
        return a[b].second < a[c].second;

    return a[b].first < a[c].first;
}

int binSearch(int k)
{
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> z;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        id[i] = i;
    }
    bool res = 1;
    sort(id+1, id+n+1);

    int health = z;

    vector<int> r;

    for (int i = 1; i <= n; i++)
    {
        
    }

    if (!res)
    {
        cout << "NIE\n";
        return 0;
    }

    cout << "TAK\n";

    


    
}