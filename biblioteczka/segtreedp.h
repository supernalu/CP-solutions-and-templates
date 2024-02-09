#include <bits/stdc++.h>

using namespace std;

class SegmentTree {

    int leaves;
    vector<int> nodeMax; // nasze drzewo
    vector<int> nodeAdd; // ile dodajemy na wierzcholku drzewa
    vector<int> nodeLeft;
    vector<int> nodeRight;

    int currIdx;
     
  public:

    SegmentTree(int n) {
        leaves = 4;
        while (n > leaves) {
            leaves *= 2;
        }
        nodeMax.assign(2 * leaves, 0);
        nodeAdd.assign(2 * leaves, 0);
        nodeLeft.resize(2 * leaves);
        nodeRight.resize(2 * leaves);
        for (int i = 0; i < leaves; ++i) {
            nodeLeft[i + leaves] = nodeRight[i + leaves] = i;
        }
        for (int i = leaves - 1; i >= 1; --i) {
            nodeLeft[i] = nodeLeft[i * 2];
            nodeRight[i] = nodeRight[i * 2 + 1];
        }
    }

    SegmentTree(vector<int> const& vec) {
        leaves = 4;
        while (vec.size() > leaves) {
            leaves *= 2;
        }
        nodeMax.assign(2 * leaves, 0);
        nodeAdd.assign(2 * leaves, 0);
        for (int i = 0; i < vec.size(); ++i) {
            nodeMax[i + leaves] = vec[i];
        }
        for (int i = leaves - 1; i >= 1; --i){
            nodeMax[i] = max(nodeMax[i * 2], nodeMax[i * 2 + 1]);
        }
        nodeLeft.resize(2 * leaves);
        nodeRight.resize(2 * leaves);
        for (int i = 0; i < leaves; ++i) {
            nodeLeft[i + leaves] = nodeRight[i + leaves] = i;
        }
        for (int i = leaves - 1; i >= 1; --i) {
            nodeLeft[i] = nodeLeft[i * 2];
            nodeRight[i] = nodeRight[i * 2 + 1];
        }
    }

    void print() {
        for (int i = 1; i <= leaves; i *= 2) {
            for (int j = i; j < 2 * i; ++j) {
                cout << nodeMax[j] << '|' << nodeAdd[j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void lazyUpdate(int i) {
        if (nodeAdd[i] != 0) {
            nodeMax[i] += nodeAdd[i];
            if (i < leaves) {
                nodeAdd[i * 2] += nodeAdd[i];
                nodeAdd[i * 2 + 1] += nodeAdd[i];
            }
            nodeAdd[i] = 0;
        }
    }

    void rangeAdd(int L, int R, int value, int i = 1) { // domyslny argument wierzcholek jeden, jego nie trzba przekazywać
        lazyUpdate(i);
        if (nodeRight[i] < L || R < nodeLeft[i]) {
            return;
        }
        if (L <= nodeLeft[i] && nodeRight[i] <= R) {
            nodeAdd[i] += value;
            lazyUpdate(i);
            return;
        }
        rangeAdd(L, R, value, i * 2);
        rangeAdd(L, R, value, i * 2 + 1);
        nodeMax[i] = max(nodeMax[i * 2], nodeMax[i * 2 + 1]);
    }

    int rangeMax(int L, int R, int i = 1) {
        lazyUpdate(i);
        if (nodeRight[i] < L || R < nodeLeft[i]) {
            return INT_MIN;
        }
        if (L <= nodeLeft[i] && nodeRight[i] <= R) {
            return nodeMax[i];
        }
        return max(rangeMax(L, R, i * 2), rangeMax(L, R, i * 2 + 1));
    }

    int operator()(int L, int R) {
      return rangeMax(L, R);
    }

    SegmentTree& operator()(int i) {
      currIdx = i + leaves;
      return *this;
    }

    // void operator=(int value) {
    //   set(currIdx, value);
    // }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    SegmentTree tree(n + 1);
    while (q--) {
        int l, r, ppl;
        cin >> l >> r >> ppl;
        if (tree(l, r - 1) + ppl <= m) {
            tree.rangeAdd(l, r - 1, ppl);
            cout << "T\n";
        }
        else {
            cout << "N\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int noTestCases = 1;

    while (noTestCases--) {
        solve();
    }
}