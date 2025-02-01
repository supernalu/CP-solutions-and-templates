#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 1e3 + 10;
constexpr ll MOD = 1e9 + 7;
int m, n;
ll s[MAXN], l[MAXN];
struct matrix {
    int length;
    int width;
    vector<vector<ll>> mat;

    matrix() : mat(MAXN, vector<ll>(MAXN, 0ll)) {}
};
matrix matrixOne;
matrix matr;

matrix times(matrix a, matrix b) {
    matrix res;
    res.length = a.length;
    res.width = b.width;
    for (int i = 1; i <= a.length; i++) {
        for (int j = 1; j <= b.width; j++) {
            res.mat[i][j] = 0;
            for (int k = 1; k <= b.length; k++) {
                res.mat[i][j] += a.mat[i][k]*b.mat[k][j];
                res.mat[i][j] %= MOD;
            }    
        }
    }
    return res;
}
matrix fastExp(matrix a, ll b) { 
    /*if (b == 0)
        return matrixOne;
    matrix tmp = fastExp(a, b/2);
    tmp = times(tmp,tmp);
    if (b%2)
        return times(tmp, a);
    return tmp;*/

    matrix ans = matrixOne;
    while(b > 0) {
        if(b % 2 == 1) ans = times(ans, a);
        a = times(a, a);
        b /= 2;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.tie(0);
    cin >> m >> n; 
    for (int i = 1; i <= m; i++)
        cin >>s[i];
    for (int i = 1; i <= m; i++)
        cin >> l[i];  
    matrixOne.length = m;
    matrixOne.width = m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++)
            matrixOne.mat[i][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        matrixOne.mat[i][i] = 1;
    }
    matr.length = m;
    matr.width = m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            matr.mat[i][j] = s[i]*s[j]+s[i]*l[j]+s[j]*l[i];
            matr.mat[i][j] %= MOD;
        }
    }
    matrix ress = fastExp(matr, n);
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        res += ress.mat[1][i];
 
        res %= MOD;
    }
    cout << res;
}