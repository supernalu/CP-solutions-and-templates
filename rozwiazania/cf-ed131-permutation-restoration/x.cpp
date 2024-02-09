#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 10;
int t, n, b[MAXN], p[MAXN], id[MAXN];
pair<int, int> interval[MAXN];
int findSmallest(int l, int r, int v, int u) {
    if (l == r)
        return l;
    int mid = (l+r)/2;
    if (v/mid <= u)
        return findSmallest(l, mid, v, u);
    else
        return findSmallest(mid+1, r, v, u);
}
int findLargest(int l, int r, int v, int u) {
    if (l == r) 
        return l;
    int mid = (l+r+1)/2;
    //cout << l << ' ' << r << ' ' << mid << '\n';
    if (v/mid >= u)
        return findLargest(mid, r, v, u);
    else
        return findLargest(l, mid-1, v, u);

}
bool cmp(int a, int c) {
    if (interval[a].second - interval[a].first == interval[c].second - interval[c].first) 
        return interval[a] < interval[c];
    return interval[a].second - interval[a].first < interval[c].second - interval[c].first;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            id[i] = i;
            interval[i].first = findSmallest(1, n, i, b[i]);
            interval[i].second = findLargest(1, n, i, b[i]);
            s.insert(i);
        }
        //for (int i = 1; i <= n; i++)
            //cout << interval[i].first << ", " << interval[i].second << "   ";
        sort(id+1, id+n+1, cmp);
        //cout << '\n';
        //for (int i = 1; i <= n; i++)
            //cout << id[i] << ' ';
        //cout << '\n';
        for (int i = 1; i <= n; i++) {
            int tmp = *(s.lower_bound(interval[id[i]].first));
            p[id[i]] = tmp;
            s.erase(tmp);
        }
        for (int i = 1; i <= n; i++)
            cout << p[i] << ' ';
        cout << '\n';
    }
}