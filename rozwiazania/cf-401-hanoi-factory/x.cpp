#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int n;
struct brick {
    int a;
    int b;
    long long h;
};
bool cmp(brick c, brick d)
{
    if (c.b == d.b)
        return c.a >= d.a; 
    return c.b >= d.b;
}
brick arr[MAXN];
long long sum[MAXN]; 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].h;
    }
    sort(arr + 1, arr + n + 1, cmp);
    //cout << '\n';
    //for (int i = 1; i <= n; i++)
        //cout << arr[i].a << ' ' << arr[i].b << ' ' << arr[i].h << '\n';
    sum[0] = 0ll;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + arr[i].h;
    int L = 1;
    int last = 1e9 + 10;
    long long res = 0;
    for (int R = 1; R <= n; R++) {
        if (arr[R].b < last)
            L = R;
        last = arr[R].a;
        res = max(res, sum[R]-sum[L-1]);
    }
    cout << res;
}