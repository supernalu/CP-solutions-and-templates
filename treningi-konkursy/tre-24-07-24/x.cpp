#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t;
long long n;
bool isPrime(int k) {
    bool res = 1;
    for (int i = 2; i*i <= k; i++) {
        if (k%i == 0)
            res = 0;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long a, b, c;
        a = 1;
        for (int i = 2; i <= n; i++) {
            if ((n-1)%i != 0 && isPrime(i)) {
                b = i;
                break;
            }
        }

        c = n-b-a;
        cout << c << ' ' << b << ' ' << ' ' << a << '\n';
            
    }
} 
