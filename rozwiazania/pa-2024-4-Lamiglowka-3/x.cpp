#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e3+10;
int n, m;
char grid[MAXN][MAXN];
int row[MAXN][30];
int column[MAXN][30];
stack<tuple<char, int, char>> res;
bool doneColumn[MAXN], doneRow[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (char j = 'A'; j <= 'Z'; j++) 
            row[i][j-'A'] = 0;
    for (int i = 1; i <= m; i++)
        for (char j = 'A'; j <= 'Z'; j++) 
            column[i][j-'A'] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        for (int j = m; j > 0; j--) {
            grid[i][j] = grid[i][j-1];
        }
        for (int j = 1; j <= m; j++) {
            row[i][grid[i][j]-'A']++;
            column[j][grid[i][j]-'A']++;
        }
    }
    //queue<tuple<char, int, char>> q;
    while (true) {
        tuple<char, int, char> v;
        bool done = 0;
        for (int i = 1; i <= n; i++) {
            //cout << i << ' ';
            //if (doneRow[i])
                //continue;
            vector<char> tmp;
            for (char j = 'A'; j <= 'Z'; j++) {
                if (row[i][j-'A'] > 0)
                    tmp.push_back(j);
            }
            if (tmp.size() == 1) {
                v = {'R', i, tmp[0]};
                //doneRow[i] = 1;
                done = 1;
                break;
            }
        }
        if (!done) {
            for (int i = 1; i <= m; i++){
                //if (doneColumn[i])
                    //continue;
                vector<char> tmp;
                for (char j = 'A'; j <= 'Z'; j++) {
                    if (column[i][j-'A'] > 0)
                        tmp.push_back(j);
                }
                if (tmp.size() == 1) {
                    v = {'K', i, tmp[0]};
                    //doneColumn[i] = 1;
                    done = 1;
                    break;
                }
            }
        }
        if (!done)
            break;
        res.push(v); 
        char type = get<0>(v), color = get<2>(v);
        int index = get<1>(v);
        //cout << type << index << color << ' ';
        if (type == 'R') {
            for (int i = 1; i <= m; i++) {
                if (grid[index][i] == color) {
                    column[i][color-'A']--;
                    grid[index][i] = 'a';
                }
            }
            row[index][color-'A'] = 0;
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (grid[i][index] == color) {
                    row[i][color-'A']--;
                    grid[i][index] = 'a';
                }
            }
            column[index][color-'A'] = 0;
        }
    } 
    cout << res.size() << '\n';
    while (!res.empty()) {
        auto tmp = res.top();
        cout << get<0>(tmp) << ' ' << get<1>(tmp) << ' ' << get<2>(tmp) << '\n';
        res.pop();
    }
    
    
}