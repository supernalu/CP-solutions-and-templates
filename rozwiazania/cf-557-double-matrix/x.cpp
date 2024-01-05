#include <bits/stdc++.h>
using namespace std;
int n, m, a[60][60], b[60][60];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            if (a[i][j] > b[i][j])
                swap(a[i][j], b[i][j]);
        }
    }
    bool poss = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] >= a[i+1][j] || b[i][j] >= b[i+1][j])
                poss = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] >= a[i][j+1] || b[i][j] >= b[i][j+1])
                poss = 0;
        }
    }
    if (poss) {
        cout << "Possible";
    }
    else {
        cout << "Impossible";
    }
}