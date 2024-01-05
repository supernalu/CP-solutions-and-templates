#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 1e6 + 10;

int n, k;
pair<int, int> point[2*MAXN];
int id[2*MAXN];

bool cmp(int a, int b)
{
    if (point[a].first == point[b].first)
        return point[a].second < point[b].second;
    return point[a].first < point[b].first;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        int a, b; cin >> a >> b;
        point[2*i-1] = {a, 1};
        point[2*i] = {b, 0};
        id[2*i-1] = 2*i-1;
        id[2*i] = 2*i;
    }
    sort(id + 1, id + 2*n + 1, cmp);

    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
    int res = 0; int h;
    for (int i = 1; i <= 2*n; i++)
    {
        if (!(id[i]%2))
        {
            s.erase({point[id[i]].first, id[i]/2});   
        }
        else
        {
            s.insert({point[id[i]+1].first, (id[i]+1)/2});
            auto u = *s.find_by_order(s.size()-k);

            

            if (s.size() >= k)
            {             
                res = max(res, u.first - point[id[i]].first);
                if (res == u.first - point[id[i]].first)
                    h = i;
            }
        }
    }
    cout << res << '\n';

    int po = point[id[h]].first, en = point[id[h]].first + res,  lol = 0;;

    for (int i = 1; i <= n; i++)
    {
        if (point[2*i-1].first <= po && point[2*i].first >= en && lol < k)
        {
            cout << i << ' ';
            lol++;
        }
    }





}