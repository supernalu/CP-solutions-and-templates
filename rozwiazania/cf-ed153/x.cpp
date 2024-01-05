#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
constexpr ll INF = 1e18 + 10;
int t, n;
string s;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> s;
        
        if (s == "()")
        {
            cout << "NO\n";
            continue;
        }
        
        n = s.size();
        vector<char> res;
        int sum = 0;
        int act = 0;
        bool poss = 1;
        for (int i = 1; i <= 2*n; i++)
        {
            //cout << act << ' ' << sum << '\n';
            if (act == n)
            {
                poss = 0;
                break;
            }
            if (sum == 2*n-i+1)
            {
                res.push_back(')');
                if (')' == s[act])
                    act++;
                else
                    act = 0;
                sum--;
            }
            else if (sum == 0)
            {
                res.push_back('(');
                if ('(' == s[act])
                    act++;
                else
                    act = 0;
                sum++;
            }
            else
            {
                if (')' == s[act])
                {
                    res.push_back('(');
                    sum++;
                    act = 0;
                }
                else
                {
                    res.push_back(')');
                    sum--;
                    act = 0;
                }
            }
        }
        if (!poss)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (auto i : res)
            cout << i;
        cout << '\n';
        
    }
}