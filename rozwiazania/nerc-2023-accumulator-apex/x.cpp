#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 1e5 + 10;
ll x;
int n;
deque<ll> a[MAXN];
void eatEnds() {
    for (int k = 1; k <= n; k++) {
        while (!a[k].empty() && a[k].front() >= 0) {
            x+= a[k].front();
            a[k].pop_front();
        }
    }
    for (int k = 1; k <= n; k++) {
        while (!a[k].empty() && a[k].back() <= 0) {
            a[k].pop_back();
        }
    }
}
void FirstCompression() {
    for (int k = 1; k <= n; k++) {
        if (a[k].empty())
            continue;
        int actSize = a[k].size();
        deque<ll> tmp;
        ll act = a[k].front();
        for (int i = 1; i < actSize; i++) {
            if ((act > 0 && a[k][i] >= 0) || (act < 0 && a[k][i] <= 0)) {
                act += a[k][i];
            }
            else {
                tmp.push_back(act);
                act = a[k][i];      
            }
        }
        if (act != 0)
            tmp.push_back(act);
        a[k].clear();
        for (auto i : tmp)
            a[k].push_back(i);
    }
}
deque<tuple<ll, ll, ll>> newA[MAXN];
void SecondCompression() {
    for (int k = 1; k <= n; k++) {
        if (a[k].empty())
            continue;
        int actSize = a[k].size();
        ll act = 0, mini = 0;
        for (int i = 0; i < actSize; i += 2) {
            ll positive = a[k][i+1], negative = a[k][i];
            act += negative;
            mini = min(mini, act);
            if (act + positive <= 0) {
                act += positive;
            }
            else {
                newA[k].push_back({mini, act, positive});
                act = 0;
                mini = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> n; 
    for (int i = 1; i <= n; i++) {
        int actSize; cin >> actSize;
        while (actSize--) {
            ll tmp; cin >> tmp; 
            a[i].push_back(tmp);
        }
    }
    eatEnds();
    FirstCompression();
    SecondCompression();
    multiset<pair<ll, int>> m;
    for (int k = 1; k <= n; k++) {
        if (newA[k].empty())
            continue;
        m.insert({-get<0>(newA[k][0]), k});
    }
    while (!m.empty()) {
        pair<ll, int> best = *m.begin();
        ll miniCost = best.first;
        int id = best.second;
        m.erase(m.begin());
        if (x - miniCost >= 0) {
            ll income = get<2>(newA[id].front()), realcost = get<1>(newA[id].front());
            x += income;
            x += realcost;
            newA[id].pop_front();
            if (newA[id].empty())
                continue;
            m.insert({-get<0>(newA[id][0]), id});
        }
        else
            break;       
    }
    cout << x;
}
