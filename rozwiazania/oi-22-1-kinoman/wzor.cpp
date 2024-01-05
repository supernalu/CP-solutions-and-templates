#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1 << 20;
constexpr int INF = 1e9 + 10;
constexpr int INI = 0;


int n, m;

int f[MAXN], w[MAXN];

int k[MAXN];

vector <int> wh[MAXN];

vector<long long> nodeMax(2 * MAXN, INI);
vector<long long> nodeLazy(2 * MAXN, INI);

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

    long long rangeMax(int queryLeft, int queryRight) {
        if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
            return nodeMax[nodeIndex];
        }
        if (nodeLeft <= queryRight && queryLeft <= nodeRight) {
            return max(left().rangeMax(queryLeft, queryRight), right().rangeMax(queryLeft, queryRight));
        }
        return -INF;
    }
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> f[i];  

    for (int i = 1; i <= m; i++)
        cin >> w[i];
    

    for (int i = 1; i <= n; i++)
        wh[f[i]].push_back(i);
    
    for (int i = 1; i <= m; i++)
    {
        wh[i].push_back(n+1);
        wh[i].push_back(n+2);
    }

    treeNode root;

    for (int i = 1; i <= m; i++)
        root.rangeAdd(wh[i][0], wh[i][1]-1, w[i]);

    long long res = root.rangeMax(1, n);

    //cout << res << ' ';

    for (int i = 1; i < n; i++)
    {
        //cout << wh[f[i]][k[f[i]]] << ' ' << wh[f[i]][k[f[i]] + 1] -1 << endl;

        root.rangeAdd(wh[f[i]][k[f[i]]], wh[f[i]][k[f[i]] + 1] -1, -w[f[i]]);

        k[f[i]]++;

        root.rangeAdd(wh[f[i]][k[f[i]]], wh[f[i]][k[f[i]] + 1] -1, w[f[i]]);

        res = max(res, root.rangeMax(i+1, n));     
    }

    cout << res;  
}