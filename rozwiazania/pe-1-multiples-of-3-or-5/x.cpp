#include <bits/stdc++.h>
using namespace std;
int main () {
    int n; cin >> n;
    int res = 0;
    for (int i = 1; i < n; i++)
        if (i%5 == 0 || i%3 == 0)
            res += i;
    cout << res;

}