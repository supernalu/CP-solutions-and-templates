#include <bits/stdc++.h>
using namespace std;
int t, n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        int a;
        cin >> n >> a;
        int gcdd = a;
        for (int i = 1; i < n; i++) {
            cin >> a;
            gcdd = __gcd(a, gcdd);
        }
        if (gcdd == 1)
            cout << "0\n";
        else if (__gcd(gcdd, n) == 1)   
            cout << "1\n";
        else if (__gcd(gcdd, n-1) == 1)
            cout << "2\n";
        else
            cout << "3\n";
    }
}