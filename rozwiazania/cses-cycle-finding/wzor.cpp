#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5010;
constexpr long long INF = 1e18;

int n, m;

vector<tuple<int, int, int>> edgel;
vector <long long> dist(MAXN, 0);
vector<int> parent(MAXN, -1);
bool poss;
int w;
vector<int> res;

void bellman_ford()
{

    
    for (int i = 1; i < n; i++)
    {
        for (auto e: edgel)
        {           

            if  (dist[get<1>(e)] > dist[get<0>(e)] + get<2>(e))
            {
                dist[get<1>(e)] = dist[get<0>(e)] + get<2>(e);
                parent[get<1>(e)] = get<0>(e);
            }
        }
    }
    for (auto e: edgel)
        {           

            if  (dist[get<1>(e)] > dist[get<0>(e)] + get<2>(e))
            {
                poss = 1;
                w = get<1>(e);
                parent[get<1>(e)] = get<0>(e);
            }
        }


}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edgel.push_back({a, b, c});
    }
    
        
            
    bellman_ford();            
            
    if (poss) {
        cout << "YES\n";
        int vOnCycle = w;

        for (int i = 0; i < n; ++i) 
        {
            vOnCycle = parent[vOnCycle];
        }

        int v = vOnCycle;
        res.push_back(v);
        do {
            v = parent[v];
            res.push_back(v);
        } while (v != vOnCycle);
        reverse(res.begin(), res.end());
        for (auto u: res) {
            cout << u << ' ';
        } cout << endl;
    }
        
    
    cout << "NO";

    

}