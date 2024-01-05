#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

struct Point {
    int x;
    int y;
};

struct Rectangle {
    int beg;
    int end;
    int idx;

    Rectangle(int beg, int end, int idx) beg(beg), end(end), idx(idx) {}

    bool operator<(Rectangle& const rhs) const {
        if (beg != rhs.beg) {
            return beg < rhs.beg;
        }
        return end < rhs.end;
    }
};

// Zmienne
int w, h, n, m;
Point start, finish;

map<int, vector<Rectangle>> down;
map<int, vector<Rectangle>> up;
map<int, vector<Rectangle>> left;
map<int, vector<Rectangle>> right;

set<int> importantX, importantY;

pair<Point, Point> rectangles[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> w >> h >> n >> m >> start.x >> start.y >> finish.x >> finish.y;

    importantX.insert(start.x);
    importantX.insert(finish.x);
    importantY.insert(start.y);
    importantY.insert(finish.y);

    for (int i = 1; i <= n; ++i) {
        cin >> rectangles[i].first.x >> rectangles[i].first.y >> rectangles[i].second.x >> rectangles[i].second.y;

        if (rectangles[i].first.x > rectangles[i].second.x) {
            swap(rectangles[i].first, rectangles[i].second);
        }
        
        down[rectangles[i].first.y].emplace_back(rectangles[i].first.x, rectangles[i].second.x, i);
        up[rectangles[i].second.y].emplace_back(rectangles[i].first.x, rectangles[i].second.x, i);
        left[rectangles[i].first.x].emplace_back(rectangles[i].first.y, rectangles[i].second.y, i);
        right[rectangles[i].second.x].emplace_back(rectangles[i].first.y, rectangles[i].second.y, i);
    }

    for (auto& vec : down) {
        sort(vec.begin(), vec.end());
    }
    for (auto& vec : up) {
        sort(vec.begin(), vec.end());
    }
    for (auto& vec : left) {
        sort(vec.begin(), vec.end());
    }
    for (auto& vec : right) {
        sort(vec.begin(), vec.end());
    }


}