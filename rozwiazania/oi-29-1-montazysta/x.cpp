#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int n;

tuple <int, int, int> a[MAXN];
int ind[MAXN];

bool cmp(int c, int b)
{
    return get<1>(a[c]) < get<1>(a[b]);
}
bool cmp2 (int x, int y)
{
    return get<1>(a[x]) < get<1>(a[y]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> get<0>(a[i]) >> get<1>(a[i]);

        get<2>(a[i]) = i;

        ind[i] = i;
    }

    sort(ind + 1, ind + n + 1, cmp);

    
    //for (int i = 1; i <= n; i++)   
        //cout << ind[i] << ' ';    
    
    int w = 1;

    int res = 0;

    set<pair<int, int>> s;

    //cout << 'j';

    for (int i = 1; i <= n; i++)
    {
        if (w + get<0>(a[ind[i]]) - 1 <= get<1>(a[ind[i]]))
        {
            //cout << 'i';
            s.insert({get<0>(a[ind[i]]), get<2>(a[ind[i]])});

            w += get<0>(a[ind[i]]);           
            res++;           
        }
        else
        {
            //cout << 'k';
            if (s.empty())
                continue;
            pair<int, int> pom = *s.rbegin();


            if (get<0>(a[ind[i]]) < pom.first)
            {
                //cout << 'h';
                w -= pom.first;
                w += get<0>(a[ind[i]]);
                //cout << "uwu";
                s.erase(pom);
                //cout << "uwu";
                s.insert({get<0>(a[ind[i]]), get<2>(a[ind[i]])});                
                //cout << "uwu";
            }
        }
    }

    cout << res << endl;

    vector<int> odp;

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        odp.push_back((*it).second);
    }

    //for (int i = 0; i < odp.size(); i++)
        //cout << odp[i].first << ' ' << odp[i].second << endl;

    sort(odp.begin(), odp.end(), cmp2);

    int r = 1;

    for (auto i : odp)
    {
        //cout << odp[i].first << ' ' << odp[i].second << endl;

        

        cout << i << ' ' << r << endl;

        r += get<0>(a[i]);
    }
     
}