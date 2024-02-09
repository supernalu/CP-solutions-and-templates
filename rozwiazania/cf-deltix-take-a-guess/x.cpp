#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int n, k;
int a[MAXN];
int rOr[MAXN];
int main() {
    cin >> n >> k;
    int first;
    for (int i = 2; i <= n; i++) {
        cout << "or 1 " << i << "\n";
        cout.flush();
        cin >> rOr[i];
        if (i == 2)
            first = rOr[2];
        else
            first = first & rOr[i];
        //cout << first << ' ';
    }
    a[1] = first;
    for (int i = 2; i <= n; i++) {
        cout << "and 1 " << i << '\n';
        cout.flush();
        int tmp; cin >> tmp;
        a[i] = rOr[i]-a[1];
        a[i] = a[i] | tmp;
        //cout << a[i] << ' '; 
    }
    sort(a+1, a+n+1);
    cout << "finish " << a[k] << '\n';
    cout.flush();
}