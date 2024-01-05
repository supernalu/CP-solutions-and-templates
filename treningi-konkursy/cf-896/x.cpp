#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n;
int a[MAXN];
int power[30];
int diff[30][30];
set<int> s;
int main()
{
    power[0] = 1;
    for (int i = 1; i < 30; i++)
        power[i] = 2*power[i-1];
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            diff[i][j] = power[i]-power[j];
            s.insert(diff[i][j]);
            //cout << diff[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << s.size() << ' ';
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
            

    }
}