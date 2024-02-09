#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

struct Rect {

    int down;
    int up;
    int left;
    int right;
    int idx;
    
    vector<int> neighbours;
    bool visited;

    char sortType;

    Rect(int l, int d, int r, int u, int i) left(l), right(r), up(u), down(d), idx(i) {
        sortType = 'l';
        visited = false;
    }

    bool operator<(Rect& const rhs) const {
        switch (sortType) {
          case 'l':
            if (left != rhs.left) {
                return left < rhs.left;
            }
            return down < rhs.down;

        }

    }
};

int w, h, n, m;
vector<Rect> rectangles;
vector<pair<int,int>> dangerousPoints;
pair<int,int> stPoint, enPoint;

void input() {
    cin >> w >> h >> n >> m; 
    cin >> stPoint.first >> stPoint.second;
    cin >> enPoint.first >> enPoint.second;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;

        if (a > c)
            swap(a, c);
        if (b > d)
            swap(b, d);
        rectangles.emplace_back(a,b,c,d,i);
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b; cin >> a >> b;
        dangerousPoints.emplace_back(a, b);
    }
}

int FindIndex(pair<int, int> point)
{
}

void findDangerous()
{
    // sort(rectangles.begin(), rectangles.end());
    // sort(dangerousPoints.begin(), dangerousPoints.end());
    set<int> sweepPoints;
    map<int, vector<int>> xToRect;
    map<int, vector<int>> xToDangerousPoints;
    for (auto [x, y] : dangerousPoints) {
        sweepPoints.insert(x);
        xToDangerousPoints[x].emplace_back(y);
    }
    for (auto& rect : rectangles) {
        sweepPoints.insert(rect.left);
        xToRect[rect.left].emplace_back(rect.down);
    }

    set<int> importantPoints;
    for (auto x : sweepPoints) {
        
    }
}

void generateGraphAxisX()
{
    set<int, decltype(&cmp)> s(&cmp);

    int it = 0;
    sort(leftDown);
    sort(rightUp);
    for (int i = 0; i <= n; i++)
    {
        while (leftDown[it].first == i)
        {
            if (!s.empty())
            {
                
            }

            s.insert(it);
            it++;
        }

    }
}
void generateGraphAxisY()
{

}

int st, en;
void GenerateGraphComplete()
{
    st = FindStartingPosition();
    en = FindEndingPosition();
    
}

void bfs() {

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    generujGraf();
    cout << bfs() << '\n';
}

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