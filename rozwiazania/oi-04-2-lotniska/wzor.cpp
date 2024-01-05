#include <bits/stdc++.h> 

using namespace std;

constexpr int MAXN = 510;

int n;
pair<int,int> d[MAXN];

vector<pair<int, int>> res;

bool koniec = 1;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n; 

    for (int i = 1; i <= n; i++)
    {   
        cin >> d[i].first;
        d[i].second = i;
    }

    while(koniec)
    {
        sort(d + 1, d + n + 1, cmp);

        for (int i = 1; i <= d[1].first; i++)
        {
            d[i+1].first--;
            res.push_back({d[1].second, d[i+1].second});
        }
        d[1].first = 0;

        koniec = 0;
        for (int i = 1; i <= n; i++)
        {
            if (d[i].first != 0)
            {
                koniec = 1;
                break;
            }
        }
    }
    for (auto i : res)
    {
        cout << i.first << ' ' << i.second << endl;
    }


    

    
    


}