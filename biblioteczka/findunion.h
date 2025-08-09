#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int rep[MAXN]; //first rep[v] = v;
int randVal[MAXN]; //make Random
int n;
void init() {
    for (int i = 1; i <= n; i++) {
        rep[i] = i;
        randVal[i] = rand();
    }
}
int find(int v) {
    if (v == rep[v])
        return v;
    return rep[v] = find(rep[v]);
}
void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (randVal[a] > randVal[b])
        swap(a, b);
    rep[a] = b;
}

