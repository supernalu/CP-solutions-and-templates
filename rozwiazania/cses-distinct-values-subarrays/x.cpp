#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
int n;
int a[MAXN];
map<int, int> m;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]] = 0;
    }
    long long L = 1;
    long long res = 0;
    for (long long R = 1; R <= n; R++) {
        m[a[R]]++;
        while(m[a[R]] > 1) {
            m[a[L]]--;
            L++;
        }
        res += R-L+1;
    }
    cout << res;

}