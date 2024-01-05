#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 110;
int t, n, a[MAXN], b[MAXN];
bool vis[2*MAXN*MAXN*MAXN];
//v to suma
void bfs(int start) {
    vis[start] = 1;
    vector<bool> stV;
    for (int i = 0; i < n; i++)
        stV.push_back(0);
    queue<pair<int, vector<bool>>> q;
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        int start = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
                start += (a[i]+a[j])*(a[i]+a[j])+(b[i]+b[j])*(b[i]+b[j]);
        bfs(start);
    }
}