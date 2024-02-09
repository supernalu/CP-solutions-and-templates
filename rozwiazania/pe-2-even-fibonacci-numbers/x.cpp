#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a = 1, b = 2, res = 0;;
    while (b <= 4'000'000) {
        if (b%2 == 0)
            res += b;
        long long c = a+b;
        a = b; b = c;
    }
    cout << res;
}