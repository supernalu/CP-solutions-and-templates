#include <bits/stdc++.h>
using namespace std; 
constexpr int MAXN = 250010;
constexpr long double INF = 1 << 30;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set_int tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pair tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
int finalPlace[MAXN];
vector<pair<int, int>> queries;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, n = 0;
    stack<int> tmp;
    while (cin >> a >> b) {
        queries.push_back({a, b});
        if (a == 1) {
            n++;
            tmp.push(b);
        }
    }
    ordered_set_int places;
    for (int i = 1; i <= n; i++) 
        places.insert(i);   
    for (int i = n; i > 0; i--) {
        int act = tmp.top();
        tmp.pop();
        int index = *places.find_by_order(act-1);
        places.erase(index);
        finalPlace[i] = index; 
    }
    ordered_set_pair s;
    int act = 0;
    for (auto query : queries) {
        int a = query.first, b = query.second;
        if (a == 1) {
            act++;
            s.insert({finalPlace[act], act});
        }
        else if (a == 3) {
            pair<long double, int> tmp = *(s.find_by_order(b-1));
            cout << tmp.second << '\n';
        }
        else {
            cout << s.order_of_key({finalPlace[b], b})+1 << '\n';   
        }
    }
}