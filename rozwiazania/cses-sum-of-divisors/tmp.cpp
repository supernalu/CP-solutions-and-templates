#include <bits/stdc++.h>
using namespace std;
int solve (int k) {
    set<int> s; 
    for (int i = 1; i <= k; i++)
        s.insert(k/i);
    return s.size();
}
int main() {
    for (int i = 1; i <= 1000000; i++) {
        cout << i << ": " << solve(i) << '\n';
    }
}