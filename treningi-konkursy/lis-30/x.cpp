#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e3;
int fenTree[MAXN];
int fenTree2D[MAXN][MAXN];
int query(int v) {
    int res = 0;
    for (int i = v; i > 0; i -= i&(-i))
        res += fenTree[i];
    return res;
}
void update(int v, int k) {
    for (int i = v; i < MAXN; i += i&(-i))
        fenTree[i] += k;
}
int query(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= i&(-i)) {
        for (int j = y; j > 0; j -= j&(-j)) {
            res += fenTree2D[i][j];
        }
    }
    return res;
}
void update(int x, int y, int k) {
    for (int i = x; i < MAXN; i += i&(-i)) {
        for (int j = y; j < MAXN; j += j&(-j)) {
            fenTree2D[i][j] += k;
        }
    }
}

int main() {

}