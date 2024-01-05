#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

struct pkt
{
    int x; 
    int y;

    int id;
};

bool cmpx(pkt a, pkt b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x < b.x;
}
bool cmpy(pkt a, pkt b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

vector<pkt> sb;

bool used[MAXN];




int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        sb.push_back({a, b, i});      
    }
    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        sb.push_back({a, b, i+n});
        
    }

    vector<int> perm;

    for (int i = 1; i <= n; i++)
        perm.push_back(i);

    int res = 1e9;

    vector<pair<int, int>> a(n);

    

    do {

        int tmp = 0;

        for (int i = 0; i < n; i++)
        {
            if (sb[i].x > sb[n + perm[i]-1].x or sb[i].y < sb[n + perm[i]-1].y)
            {
                tmp = 1e9 + 10;

                //cout << sb[i].x << ' ' << sb[n + perm[i]-1].x << ' ' << sb[i].y << ' ' << sb[n + perm[i]-1].y << endl;

                break;
            }
            

            tmp += sb[n + perm[i]-1].x - sb[i].x + sb[i].y - sb[n + perm[i]-1].y;
            
        }

        

        
        if (tmp < res)
        {
            for (int i = 0; i < n; i++)
                a[i] = {i+1, perm[i]};
            res = min(res, tmp);

            break;
        }

        
    } while (next_permutation(perm.begin(), perm.end()));



    cout << res << endl;

    for (auto i : a)
        cout << i.first << ' ' << i.second << endl;









}