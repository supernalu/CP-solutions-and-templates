#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e4 + 10;

int n;

vector<int>b[MAXN];
vector<int>complete;
map<int, int>m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

   
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;

        for (int j = 1; j <= k; j++)
        {
            int tmp; cin >> tmp;
            b[i].push_back(tmp);
            complete.push_back(tmp);
        }
    }

    sort(complete.begin(), complete.end());

    int k = 1;
    for (auto i : complete)
    {
        m[i] = k; k++;
    }

    int r1 = 0, r2 = n-1;

    for (int i = 1; i <= n; i++)
    {
        b[i][0] = m[b[i][0]];
        for (int j = 1; j < b[i].size(); j++)
        {
            b[i][j] = m[b[i][j]];
            if (b[i][j]-b[i][j-1] != 1)
            {
                r1++; r2++;
            }
        }
    }

    cout << r1 << ' ' << r2;
}