#include <bits/stdc++.h>

using namespace std;

constexpr int LEAVES = 16;
constexpr int INI = 0;
constexpr int INF = 1e9 + 7;

// = , nax
// + , +
// = , +


vector<vector<int>> segtree(2 * LEAVES, vector<int> (3, 0));
vector<int> lazy(2 * LEAVES, INI);



struct Node {
    int left, right, index;

    Node(int l, int r, int i) {
        left = l;
        right = r;
        index = i;
        lazyUpdate();
    }

    Node goLeft() {
        return Node(left, (left + right) / 2, index * 2);
    }

    Node goRight() {
        return Node((left + right) / 2 + 1, right, index * 2 + 1);
    }

    void lazyUpdate() {
        if (lazy[index] != INI) {
            if (index < LEAVES) {
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] %= 3;
            vector<int> tmp(3);

            for (int i = 0; i < 3; i++)
            {
                tmp[(i + lazy[index])%3] = segtree[index][i];
            }

            segtree[index] = tmp;
            lazy[index] = INI;
        }
    }

    void addRange(int L, int R) {
        if (L <= left && right <= R) {
            lazy[index]++;
            lazyUpdate();
        } 
        else if (!(L > right || R < left)) {
            goLeft().addRange(L, R);
            goRight().addRange(L, R);
            for (int i = 0; i < 3; i++)
                segtree[index][i] = segtree[index * 2][i] + segtree[index * 2 + 1][i];
        }
    }

    int sumRange() {
        return segtree[1][2];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n = LEAVES - 1;

    for (int i = LEAVES + 1; i <= LEAVES + n; i++)
    {
        segtree[i][0] = 1; 
    }

    for (int i = LEAVES - 1; i > 0; i--)
    {
        segtree[i][0] = segtree[2*i][0] + segtree[2*i + 1][0];
    }

    Node root(0, LEAVES - 1, 1);
    root.addRange(3, 6);
    root.addRange(4, 7);
    cout << root.sumRange() << endl << root.sumRange();
    
}