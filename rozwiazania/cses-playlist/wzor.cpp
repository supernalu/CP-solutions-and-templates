#include <bits/stdc++.h>
 
using namespace std;

map<int, int> mp;
int n, res, tmp;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
 
    vector<int> tab(n);
 
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    } tab.push_back(tab[n - 1]);
 
    int R = 0;
    for (int L = 0; L < n; ++L){
        while (mp[tab[R]] == 0) {
            mp[tab[R]] = 1;
            ++R;
        }
        res = max(res, R - L);
        mp[tab[L]] = 0;
    }
    cout << res << endl;
}