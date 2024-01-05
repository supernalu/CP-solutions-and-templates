#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n; 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << "{";
    for (ll i = 1; i <= 1000000; i++)
    {
       ll j = i*i;
            string k = to_string(j);
            sort(k.begin(), k.end());
            if (k == "00123456789")
                cout << j <<  ", ";
    }
    cout << "}";
}