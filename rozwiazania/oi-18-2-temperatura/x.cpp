#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

int n;
pair<int, int> temp[MAXN];

bool cmp(int a, int b)
{
    if (temp[a].first == temp[b].first)
        return a < b;
    return temp[a].first < temp[b].first;
}
set<int, decltype(&cmp)> s(&cmp);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b; cin >> a >> b;
        temp[i] = {a, b};
    }
    int res = 0;
    int R = 1; int mini = temp[1].first;
    
    for (int L = 1; L <= n; L++)
    {
        if (L == R)
            s.insert(L);
        mini = temp[*(s.rbegin())].first;

        while (temp[R].second >= mini && R <= n)
        {   
            //cout << mini << ' ';
            mini = max(mini, temp[R].first);
            s.insert(R);
            R++;
        }
        res = max(res, R-L);
        //cout << mini << '\n';

        s.erase(L);
    }

    cout << res;
}