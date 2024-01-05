#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 5e5+10;

int n, st;
pair<ll,ll>cost[MAXN];
ll result = 0;
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> st;
    res.push_back(st);

    for (int i = 1; i < n; i++)
    {
        ll a, b; cin >> a >> b;
        cost[i] = {a, b};
        result += min(a, b);
    }
    bool poss = 1;
    ll mini = 1e9; int id;

    for (int i = 1; i <= st; i++)
    {
        if (cost[i].first > cost[i].second)
        {
            poss = 0;
            break;
        }
        mini = min(mini, cost[i].second-cost[i].first);
        if (mini == cost[i].second-cost[i].first)
            id = i;
    }
    if (poss)
    {
        result += mini;
    }


    poss = 1; mini = 1e9;
    for (int i = 1; i <= n-st+1; i++)
    {
        if (cost[i].first < cost[i].second)
        {
            poss = 0;
            break;
        }
        mini = min(mini, cost[i].first-cost[i].second);
        if (mini == cost[i].first-cost[i].second)
            id = i;
    }
    if (poss)
    {
        result += mini;
    }


    vector<bool> tmp;
    set<int> s; s.insert(n);
    for (int i = 1; i < n; i++)
    {
        s.insert(i);
        
        if (cost[i].first < cost[i].second)
            tmp.push_back(0);
        else
            tmp.push_back(1);
    }
    s.erase(st);
    if (poss && tmp[id-1]==1)
        tmp[id-1] = 0;
    else if (poss && tmp[id-1] == 0)
        tmp[id-1] = 1;

    if (tmp[n-2] == 0)
        tmp.push_back(1);
    else
        tmp.push_back(0);

    vector<int> temporary;
    for (int i = 0; i < n-1; i++)
    {
        //cout << tmp[i] << ' ';
        if (tmp[i] == 0)
        {
            temporary.push_back(*(s.begin()));
            s.erase(s.begin());
        }
        else 
        {
            temporary.push_back(*(--s.end()));
            s.erase(--s.end());
        }
        if (tmp[i] != tmp[i+1])
        {
            //out << "lmoa";
            reverse(temporary.begin(), temporary.end());
            for (auto i : temporary)
                res.push_back(i);
            temporary.clear();
        }
    }
        

    
    cout << result << '\n';
    

    for (auto i : res)
        cout << i << ' ';
}