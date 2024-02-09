#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;      
        v.push_back({x, i});       
    }
    sort(v.begin(), v.end());
    for (int i = 2; i < v.size(); i++)
    {
        if (v[i-2].first + v[i-1].first > v[i].first)
        {
            vector<pair<int, int>> tmp;

            for (int j = i-2; j <= i; j++)
                tmp.push_back(v[j]);

            sort(tmp.begin(), tmp.end(), cmp);
            
            cout << tmp[0].first << ' ' << tmp[1].first << ' ' <<  tmp[2].first << '\n';
            
            return 0;
        }
    }
    cout << "NIE\n";
}