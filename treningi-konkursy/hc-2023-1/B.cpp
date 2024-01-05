#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int t, p;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int Case = 1; Case <= t; Case++)
    {
        cin >> p;
        int sum = 0;
        vector<int> res;
        for (int i = 2; i*i <= p; i++)
        {
            while(p%i == 0)
            {
                res.push_back(i);
                sum += i;
                p /= i;
            }
        }
        if (p > 2)
        {
            res.push_back(p);
            sum += p;
            p = 1;
        }
        if (sum > 41)
        {
            cout << "Case #" << Case << ": -1\n";
        }
        else
        {
            while (sum < 41)
            {
                sum++;
                res.push_back(1);
            }
            cout << "Case #" << Case << ": " << res.size() << ' ';
            for (auto i : res)
                cout << i << ' ';
            cout << '\n';
        }

    }
}