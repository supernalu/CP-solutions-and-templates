#include <bits/stdc++.h>

using namespace std;

constexpr int LEAVES = 1000000;
constexpr int INI = 0;
constexpr int INF = 1e9 + 7;

int n;

vector<int> segtree(2 * LEAVES, INI);
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
            segtree[index] += lazy[index];
            lazy[index] = INI;
        }
    }

    void addRange(int L, int R, int value) {
        if (L <= left && right <= R) {
            lazy[index] += value;
            lazyUpdate();
        } 
        else if (!(L > right || R < left)) {
            goLeft().addRange(L, R, value);
            goRight().addRange(L, R, value);
            segtree[index] = max(segtree[index * 2], segtree[index * 2 + 1]);
        }
    }

    int maxRange(int L, int R) {
        if (L <= left && right <= R) {
            return segtree[index];
        } 
        else if (!(L > right || R < left)) {
            return max(goLeft().maxRange(L, R), goRight().maxRange(L, R));
        }
        return -INF;    
    }
};

int m, z;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Node root(0, LEAVES - 1, 1);

    cin >> n >> m >> z;

    for (int q = 0; q < z; q++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if (root.maxRange(a, b-1) + c <= m)
        {
            cout << "T\n";

            root.addRange(a, b-1, c);
        }
        else
            cout << "N\n";
    }
}

