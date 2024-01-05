#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int MAXN = 1e5 + 10;
 
int t;
 
int n;
 
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> t;
 
    while (t--)
    {
        cin >> n;
 
        vector<long long>a;
 
        for (int i = 1; i <= n; i++)
        {
            int b;
 
            cin >> b;
 
            if (b != 0)
                a.push_back(b);
        }
 
        if (a.empty())
        {
            cout << "0\n";
            continue;
        }

        a.push_back(0);
 
        sort(a.begin(), a.end());
 
        for (int i = 1; i < a.size() - 1; i++)
        {
            a[i] += a[i-1];
        }
 
        cout << max((long long)1, a[a.size()-1] - a[a.size()-2]) << '\n';
 
    }
}