#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n;

pair<int, int> point[MAXN];

unordered_map<int, long long> increasing, decreasing, horizontal, vertical;
unordered_map<int, bool> visI, visD, visH, visV;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int a, b; cin >> a >> b;
            point[i] = {a, b};
        }
        for (int i = 1; i <= n; i++)
        {
            int a = point[i].first, b = point[i].second;

            vertical[b]++;
            horizontal[a]++;
            increasing[b-a]++;
            decreasing[a+b]++;
        }
        long long res = 0;
        for (int i = 1; i <= n; i++)
        {
            int a = point[i].first, b = point[i].second;

            if (visV[b] == 0)
            {
                visV[b] = 1;
                res += vertical[b]*(vertical[b]-1);
            }
            if (visH[a] == 0)
            {
                visH[a] = 1;
                res +=  horizontal[a]*(horizontal[a]-1);
            }
            if (visI[b-a] == 0)
            {
                visI[b-a] = 1;
                res += increasing[b-a]*(increasing[b-a]-1);
            }
            if (visD[b+a] == 0)
            {
                visD[b+a] = 1;
                res += decreasing[b+a]*(decreasing[b+a]-1);
            }
            
        }
        

        cout << res << '\n';


        for (int i = 1; i <= n; i++)
        {
            int a = point[i].first, b = point[i].second;

            vertical[b] = 0;
            horizontal[a] = 0;
            increasing[b-a] = 0;
            decreasing[a+b] = 0;
            visV[b] = 0;
            visH[a] = 0;
            visI[b-a] = 0;
            visD[b+a] = 0;
        }
    }
}