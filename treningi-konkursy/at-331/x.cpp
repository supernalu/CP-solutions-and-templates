#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, m, l;
long long a[MAXN];
long long b[MAXN];
pair<int, int> ex[MAXN];
bool cmp(int d, int c) {
    //cout << b[d] << ' ' << b[c] << '\n';
    if (b[d] == b[c])
        return c < d;
    //cout << "good";
    return b[d] > b[c];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        
    }
    set<int, decltype(cmp)*> s(cmp);
    for (int i = 1; i <= m; i++)
        s.insert(i);
    for (int i = 1; i <= l; i++)
        cin >> ex[i].first >> ex[i].second;
    sort(ex+1, ex+l+1);
    deque<int> bad;
    int ws = 1;
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!bad.empty())
        {
            //cout << *(bad.begin()) << ' ';
            s.insert(*(bad.begin()));
            bad.pop_front();
        }
        //cout << '\n';
        while (ws <= l && ex[ws].first == i)
        {
            bad.push_back(ex[ws].second);
            s.erase(ex[ws].second);
            ws++;
        }
        //for (auto u : s)
            //cout << u << ' ';
        //cout << '\n';
        int tmp = *(s.begin());
        res = max(res, a[i]+b[tmp]);
    }
    cout << res;
}