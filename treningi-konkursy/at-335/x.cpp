#include <bits/stdc++.h>
//#include "debug.cpp"
using namespace std;
int when[50][50];
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= n+1; j++) {
            when[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            when[i][j] = 0;
        }
    }
    
    int act = 1;
    pair<int, int> last = {1, 1};
    char move = 'U';
    while (act <= n*n-1) {
        //cout << last.first << ' ' << last.second << ' ' << move << '\n';
        when[last.first][last.second] = act;
        act++;
        switch(move) {
            case 'U':
                last.second++;
                if (when[last.first][last.second] != 0) {
                    last.second--;
                    move = 'R';
                    last.first++;
                }
                break;
            case 'D':
                last.second--;
                if (when[last.first][last.second] != 0) {
                    last.second++;
                    move = 'L';
                    last.first--;
                }
                break;
            case 'L':
                last.first--;
                if (when[last.first][last.second] != 0) {
                    last.first++;
                    move = 'U';
                    last.second++;
                }
                break;
            case 'R':
                last.first++;
                if (when[last.first][last.second] != 0) {
                    last.first--;
                    move = 'D';
                    last.second--;
                }
                break;
            
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == (n+1)/2 && j == (n+1)/2)
                cout << 'T' << ' ';
            else
                cout << when[i][j] << ' ';
        }
        cout << '\n';
    }
}