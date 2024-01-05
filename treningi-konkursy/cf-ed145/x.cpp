#include<bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 10;


int t;
int n, k;
vector<int> dp[31][500];



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        if (k == 0)
        {
            while (n--)
                cout << -1 << ' ';
            cout << '\n';
            
            continue;
        }

        vector<int> res;

        for (int i = n; i >= 1; i--)
        {
            if (k >= i)
            {
                k-= i;
                res.push_back(999);
                continue;
            }
            if (k > 0)
            {
                res.push_back(999);
                k--;

                while (k > 0)
                {
                    res.push_back(-1);
                    k--;
                }

                res.push_back(-1000);
            }

            
            while (res.size() < n)
                res.push_back(-1);
            break;
        }

        for (auto i : res)
            cout << i << ' ';
        cout << '\n';
    }
}