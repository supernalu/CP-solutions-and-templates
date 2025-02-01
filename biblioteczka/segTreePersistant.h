#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    Node* l;
    Node* r;
    ll sum;

    Node(ll sum) : l(nullptr), r(nullptr), sum(sum) {}
    Node(Node* l, Node* r) : l(l), r(r), sum(0) {
        if (l) {
            sum += l->sum;
        }
        if (r) {
            sum += r->sum;
        }
    }
};

Node* build(int l, int r, vector<int> const& arr) {
    if (l == r) {
        return new Node(arr[l]);
    }
    int m = (l+r)/2;
    return new Node(build(l, m, arr), build(m + 1, r, arr));
}

// zapytanie na przedziale [L, R]
ll query(Node* v, int l, int r, int L, int R) {
    if (r < L || R < l) {
        return 0;
    }
    if (L <= l && r <= R) {
        return v->sum;
    }
    int m = (l+r)/2;
    return query(v->l, l, m, L, R) + query(v->r, m + 1, r, L, R);
}

// przypisz na indeksie i liczbe x
Node* modify(Node* v, int l, int r, int i, int x) {
    if (l == r) {
        return new Node(x);
    }
    int m = (l + r) / 2;
    if (i <= m) {
        return new Node(modify(v->l, l, m, i, x), v->r);
    }
    return new Node(v->l, modify(v->r, m + 1, r, i, x));
}