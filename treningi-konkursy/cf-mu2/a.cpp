#include <bits/stdc++.h>
using namespace std;
char s[100'010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s+1;
    int n = strlen(s+1);
    int res = 0;
    int act = 0;
    for (int i = n; i > 0; i--) {
        act++;
        if (s[i] != '0') {
            res++;
            if (i-1 < act || (i-1 == act && s[1] < s[i]))
                break;
            act = 0;
        }    
    }
    cout << res;
}