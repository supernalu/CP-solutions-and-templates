#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 10;
constexpr int MAXA = 1e6 + 10;
constexpr pair<int, int> falsePair = {-1, -1};
int n, k, a[MAXN], ile[MAXA];
pair<int, int> solve(int dl) {
    for (int i = 1; i <= n; i++) 
        ile[a[i]] = 0;
    int rozne = 0;
    for (int i = 1; i <= dl; i++) {
        ile[a[i]]++;
        if (ile[a[i]] == 1) 
            rozne++;
    }
    if (rozne <= k) 
         return {1, dl};
    for (int i = dl+1; i <= n; i++) {
        ile[a[i]]++;
        if (ile[a[i]] == 1) 
            rozne++;
        ile[a[i-dl]]--;
        if(ile[a[i-dl]] == 0) 
            rozne--;
        if (rozne <= k) 
           return {i-dl+1, i}; 
    }
    return {-1, -1};
}
pair<int, int> binSearch(int l, int r) {
    if (l == r) {
        return solve(l);
    }
    int mid = (l+r+1)/2;
    pair<int, int> res = solve(mid);
    if (res == falsePair) 
        return binSearch(l, mid-1);
    else
        return binSearch(mid, r);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pair<int, int> res = binSearch(1, n);
    cout << res.first << ' ' <<  res.second;
}