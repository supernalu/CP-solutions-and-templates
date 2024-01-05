#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 5e5 + 10;
int t, n;
string s;
vector<char> cop;
int dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> s; 
        n = s.size();
        bool res = 1;
        int current = 0;
        for (int i = 0; i <= n; i++)
            dp[i] = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+')
                current++;
            else if (s[i] == '-')
                current--;
            else if (s[i] == '0' && current <= 1)
                res = 0;
        }
        current = 0;
        int maxi = 0, mini = 1e9 + 10;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+')
                current++;
            else if(s[i] == '-')
                current--;
            else if (s[i] == '1')
                maxi = max(maxi, current);
            else
                mini = min(mini, current);
        
        }
        if (res == 0 || maxi >= mini)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
}
