#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 1 << 18;
constexpr int INF = 1e9 + 10;
constexpr int INI = 0;

vector<int> nodeMax(2 * MAXN, INI);
vector<int> nodeLazy(2 * MAXN, INI);

struct treeNode {
    int nodeLeft, nodeRight, nodeIndex;

    treeNode(int left = 0, int right = MAXN - 1, int index = 1) {
        nodeLeft = left;
        nodeRight = right;
        nodeIndex = index;
        lazyUpdate();
    }

    treeNode left() {
        return treeNode(nodeLeft, (nodeLeft + nodeRight) / 2, nodeIndex * 2);
    }

    treeNode right() {
        return treeNode((nodeLeft + nodeRight) / 2 + 1, nodeRight, nodeIndex * 2 + 1);
    }

    void lazyUpdate() {
        if (nodeLazy[nodeIndex] != INI) {
            if (nodeLeft != nodeRight) {
                nodeLazy[2 * nodeIndex] += nodeLazy[nodeIndex];
                nodeLazy[2 * nodeIndex + 1] += nodeLazy[nodeIndex];
            }
            nodeMax[nodeIndex] += nodeLazy[nodeIndex];
            nodeLazy[nodeIndex] = INI;
        }
    }

    void rangeAdd(int queryLeft, int queryRight, int queryValue) {
        if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
            nodeLazy[nodeIndex] += queryValue;
            lazyUpdate();
            return;
        }
        if (nodeLeft <= queryRight && queryLeft <= nodeRight) {
            left().rangeAdd(queryLeft, queryRight, queryValue);
            right().rangeAdd(queryLeft, queryRight, queryValue);
            nodeMax[nodeIndex] = max(nodeMax[nodeIndex * 2], nodeMax[nodeIndex * 2 + 1]);
        }
    }

    int rangeMax(int queryLeft, int queryRight) {
        if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
            return nodeMax[nodeIndex];
        }
        if (nodeLeft <= queryRight && queryLeft <= nodeRight) {
            return max(left().rangeMax(queryLeft, queryRight), right().rangeMax(queryLeft, queryRight));
        }
        return -INF;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    treeNode root;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        root.rangeAdd(i, i, tmp);
    }

    while (q--) {
        int queryType;
        cin >> queryType;

        switch (queryType) {
            case 1:
                int x, value;
                cin >> x >> value;
                root.rangeAdd(x, x, value);
                break;

            case 2:
                int left, right;
                cin >> left >> right;
                cout << root.rangeMax(left, right) << '\n';
                break;
        }
    }
    return 0;
}