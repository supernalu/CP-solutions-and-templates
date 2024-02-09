#include <bits/stdc++.h>
using namespace std;

int main() {
    int res = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            int k = i*j;
            string s = to_string(k);
            int n = s.size();
            bool pos = 1;
            for (int i = 0; i < n; i++) {
                if (s[i] != s[n-i-1])
                    pos = 0;
            }
            if (pos)
                res = max(res, k);
        }
    }
    cout << res;
}