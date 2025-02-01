#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 600;
int t, n, m;

const char* str = R"(
...................................................................
..***....*...***....***......*...*****....**...*****...***....***..
.*...*..**..*...*..*...*....**...*.......*.....*...*..*...*..*...*.
.*...*...*......*......*....**...*......*..........*..*...*..*...*.
.*...*...*.....*.....**....*.*...****...****.......*...***...*...*.
.*...*...*....*........*...*.*.......*..*...*.....*...*...*...****.
.*...*...*...*.........*..*****......*..*...*.....*...*...*......*.
.*...*...*..*......*...*.....*...*...*..*...*....*....*...*.....*..
..***....*..*****...***.....***...***....***.....*.....***....**...
...................................................................
)";

vector<int> szer {7, 4, 7, 7, 7, 7, 7, 7, 7, 7};
vector<vector<char>> tab(MAXN, vector<char>(MAXN, '.'));

bool f(int R, int C, vector<vector<char>>& arr) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if (tab[R + i][C + j] == '*' && arr[i][j] == '.' ||
                tab[R + i][C + j] == '.' && arr[i][j] == '*') {
                    return false;
                } 
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    stringstream ss(str);
    vector<vector<vector<char>>> arr(10, vector<vector<char>>(10, vector<char>(7)));
    
    for (int r = 0; r < 10; ++r) {
        for (int i = 0; i < 10; ++i) {
            for (int c = 0; c < szer[i]; ++c) {
                ss >> arr[i][r][c];
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int r = 0; r < 10; ++r) {
            for (int c = 0; c < szer[i]; ++c) {
                int ile = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (r + dr < 0 || r + dr == 10 || c + dc < 0 || c + dc == szer[i]) {
                            continue;
                        }
                        if (arr[i][r + dr][c + dc] == '*') {
                            ++ile;
                        }
                    }
                }
                if (ile == 0) {
                    arr[i][r][c] = 'x';
                }
                
                // cout << arr[i][r][c];
            }
            // cout << '\n';
        }
        // cout << "\n\n";
    }
     
   // cout << str;
    cin >> t;
    while (t--) {
        cin >> n >> m; 
            
        for (int i = 1; i <= n + 10; ++i) {
            for (int j = 1; j <= m + 10; ++j) {
                tab[i][j] = '.';
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> tab[i][j];
            }
        }
        
        vector<tuple<int, int, int>> res;

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (f(i, j, arr[k])) {
                        res.emplace_back(i, j, k);
                    }
                }
            }
        }

        if (res.empty()) {
            cout << '.' << '\n';
        }
        else {
            for (auto [a, b, c] : res) {
                cout << c;
            }
            cout << '\n';
        } 
    }
}