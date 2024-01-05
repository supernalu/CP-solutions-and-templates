#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1 << 3;
constexpr int INF = 1e9 + 10;
constexpr int INI = 0;

int n, q;

vector<long long> nodeSum(2 * MAXN, INI);
vector<pair<long long, int>> nodeLazyAdd(2 * MAXN, {INI, INI});
vector<pair<long long, int>> nodeLazyChange(2 * MAXN, {INI, INI});

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

    void lazyUpdateAdd()
    {
        nodeSum[nodeIndex] += nodeLazyAdd[nodeIndex].first*(nodeRight - nodeLeft + 1);
        if (nodeLeft != nodeRight)
        {
            nodeLazyAdd[2*nodeIndex].first += nodeLazyAdd[nodeIndex].first;
            nodeLazyAdd[2*nodeIndex + 1].first += nodeLazyAdd[nodeIndex].first;

            nodeLazyAdd[2*nodeIndex].second = nodeLazyAdd[nodeIndex].second;
            nodeLazyAdd[2*nodeIndex + 1].second = nodeLazyAdd[nodeIndex].second;

        }
        nodeLazyAdd[nodeIndex] = {INI, INI};
    }

    void lazyUpdateChange()
    {   
        nodeSum[nodeIndex] = nodeLazyChange[nodeIndex].first*(nodeRight - nodeLeft + 1);
        if (nodeLeft != nodeRight)
        {
            nodeLazyChange[2*nodeIndex] = nodeLazyChange[nodeIndex];
            nodeLazyChange[2*nodeIndex + 1] = nodeLazyChange[nodeIndex];
        }  
        nodeLazyChange[nodeIndex] = {INI, INI};
    }

    void lazyUpdate() 
    {
        //cout << nodeIndex << ' ' << nodeLeft << ' ' << nodeRight << ' ' << nodeLazyAdd[nodeIndex].first << ' ' << ' ' << nodeLazyChange[nodeIndex].first << ' ' <<  nodeSum[nodeIndex] << endl; 

        if (nodeLazyAdd[nodeIndex].second > nodeLazyChange[nodeIndex].second)
        {
            if (nodeLazyChange[nodeIndex].first != INI)
            {
                lazyUpdateChange();
            }
            lazyUpdateAdd();
        }
        else if (nodeLazyAdd[nodeIndex].second < nodeLazyChange[nodeIndex].second)
        {
            if (nodeLazyAdd[nodeIndex].first != INI)
            {
                lazyUpdateAdd();
            }
            lazyUpdateChange();
        }
        //cout << nodeIndex << ' ' << nodeLeft << ' ' << nodeRight << ' ' << nodeLazyAdd[nodeIndex].first << ' ' << ' ' << nodeLazyChange[nodeIndex].first << ' ' <<  nodeSum[nodeIndex] << endl << endl;

    }

    void rangeChange(int queryLeft, int queryRight, pair<int, int> queryValue)
    {
        if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
            nodeLazyChange[nodeIndex] = queryValue;
            lazyUpdate();
            return;
        }
        if (nodeLeft <= queryRight && queryLeft <= nodeRight) {
            left().rangeChange(queryLeft, queryRight, queryValue);
            right().rangeChange(queryLeft, queryRight, queryValue);
            nodeSum[nodeIndex] = nodeSum[nodeIndex * 2] + nodeSum[nodeIndex * 2 + 1];
        }
    }

    void rangeAdd(int queryLeft, int queryRight, pair<int,int> queryValue) {
        if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
            nodeLazyAdd[nodeIndex].first += queryValue.first;
            nodeLazyAdd[nodeIndex].second = queryValue.second;
            lazyUpdate();
            return;
        }
        if (nodeLeft <= queryRight && queryLeft <= nodeRight) {
            left().rangeAdd(queryLeft, queryRight, queryValue);
            right().rangeAdd(queryLeft, queryRight, queryValue);
            nodeSum[nodeIndex] = nodeSum[nodeIndex * 2] + nodeSum[nodeIndex * 2 + 1];
        }
    }

    int rangeSum(int queryLeft, int queryRight) {
        if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
            return nodeSum[nodeIndex];
        }
        if (nodeLeft <= queryRight && queryLeft <= nodeRight) {
            return left().rangeSum(queryLeft, queryRight) + right().rangeSum(queryLeft, queryRight);
        }
        return 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    treeNode root;

    for (int i = 1; i <= n; i++)
    {
        int a; 

        cin >> a;

        root.rangeChange(i, i, {a, i});
    }

    for (int i = 0; i < q; i++)
    {
        int type;

        cin >> type;

        if (type == 1)
        {
            int a, b, c;

            cin >> a >> b >> c;

            root.rangeAdd(a, b, {c, i+n+1});
        }
        else if (type == 2)
        {
            int a, b, c;

            cin >> a >> b >> c;

            root.rangeChange(a, b, {c, i+n+1});
        }
        else
        {
            int a, b;

            cin >> a >> b;

            cout << root.rangeSum(a, b) << '\n';
        }
    }
}