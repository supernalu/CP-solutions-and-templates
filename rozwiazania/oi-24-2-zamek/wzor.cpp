#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using rectangle = tuple<int, int, int, int>;
using point = pair<int, int>;

// in: vector<pair<rectangle, int>> rectanglesWithIdSortedByX, vector<point> pointsSortedByX, vector<int> importantX
// inside: set<pair<int, int>> sweepline
// out: unordered_map<point, vector<int>> toVertex

// in: unordered_map<point, vector<int>> toVertex
// inside: 
// out: vector<int> adj

// in: int vBegin, int vEnd, vector<int> adj, vector<point> dangerousPoints
// inside: queue<int> bfsQueue
// out: int distEnd
int w, h, n, m;
vector<rectangle> rectangles; // stale
point p, k;

set<int> importantX;
unordered_map<int, vector<int>> xToStartingSegments;
unordered_map<int, vector<int>> xToEndingSegments;
unordered_map<int, vector<int>> xToDangerousY;

int a, b;
vector<bool> vis(1'000'000, false);
vector<int> adj[1'000'000];
int dist[1'000'000];
void solve() {
    set<pair<int, int>> sweep;
    for (auto line : importantX) {
        //cout << line << ' ';
        vector<int> deletedRectIdx;
        for (auto rectIdx : xToEndingSegments[line]) {
            auto [x1, y1, x2, y2] = rectangles[rectIdx];
            sweep.erase({y2, rectIdx});
            deletedRectIdx.emplace_back(rectIdx);
        }
        
        vector<int> addedRectIdx;
        for (auto rectIdx : xToStartingSegments[line]) {
            auto [x1, y1, x2, y2] = rectangles[rectIdx];
            sweep.insert({y2, rectIdx});
            addedRectIdx.emplace_back(rectIdx);
        }
        
        for (auto rectIdx : deletedRectIdx) {
            auto [x1, y1, x2, y2] = rectangles[rectIdx];
            if (!sweep.empty()) {
                auto begIt = sweep.upper_bound({y1, INT_MIN});
                auto endIt = sweep.lower_bound({y2, INT_MIN});
                
                ++endIt;
                
                for (; begIt != endIt; begIt++) {
                    adj[rectIdx].push_back((*begIt).second);
                    adj[(*begIt).second].push_back(rectIdx);
                }
                
            }
        }
        
        for (auto rectIdx : addedRectIdx) {
            auto [x1, y1, x2, y2] = rectangles[rectIdx];
            auto it = sweep.lower_bound({y2, INT_MIN});
            if (it != sweep.begin()) {
                auto it2 = it;
                --it2;
                adj[(*it).second].emplace_back((*it2).second);
                adj[(*it2).second].emplace_back((*it).second);
            }
            auto it2 = it;
            ++it2;
            if (it2 != sweep.end()) {
                adj[(*it).second].emplace_back((*it2).second);
                adj[(*it2).second].emplace_back((*it).second);
            }
        }
        for (auto y : xToDangerousY[line]) {
            auto it = sweep.lower_bound({y, INT_MIN});
            vis[(*it).second] = true;
        }
        if (line == p.first) {
            auto it = sweep.lower_bound({p.second, INT_MIN});
            a = (*it).second;
        }
        if (line == k.first) {
            auto it = sweep.lower_bound({k.second, INT_MIN});
            b = (*it).second;
        }
        
    }
}

void bfs(int st) {
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    dist[st] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (vis[u])
                continue;
            dist[u] = dist[v]+1;
            vis[u] = 1;
            q.push(u);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> w >> h >> n >> m;
    rectangles.resize(n);

    cin >> p.first >> p.second >> k.first >> k.second;
    importantX.emplace(p.first);
    importantX.emplace(k.first);
    
    for (int i = 0; i < n; ++i) {
        auto& [x1, y1, x2, y2] = rectangles[i];
        cin >> x1 >> y1 >> x2 >> y2;
        importantX.emplace(x1);
        importantX.emplace(x2);
        xToStartingSegments[x1].emplace_back(i);
        xToEndingSegments[x2].emplace_back(i);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        xToDangerousY[x].emplace_back(y);
        importantX.emplace(x);
    }
    
    solve();
    bfs(a);
    cout << dist[b];
}

