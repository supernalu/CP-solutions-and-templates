#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n; 
map<string, int> m;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (ll i = 1; i <= 100000; i++)
    {
        ll j = i*i;  
            string k = to_string(j);
            sort(k.begin(), k.end());
            if (k.size() == 9)
            m[k] = 0;
        
    }
    for (ll i = 1; i <= 100000; i++)
    {
       ll j = i*i;
            string k = to_string(j);
            sort(k.begin(), k.end());
            if (k.size() == 9)
            m[k]++;
        
    }
    int maxi = 0;
    string h;
    for (auto u : m) {
        maxi = max(u.second, maxi);
        if (u.second == maxi) {
            h = u.first;
        }
        cout << u.first << ' ' << u.second << '\n';
    }
    cout << maxi << ' ' << h << '\n';
    for (ll i = 1; i <= 100000; i++)
    {
       ll j = i*i;
            string k = to_string(j);
            sort(k.begin(), k.end());
            if (k == h)
                cout << j <<  ", ";
    }

}
    
