#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
ll n;

ll powerNine[16];

void init()
{
    powerNine[0] = 1;

    for (int i = 1; i < 16; i++)
        powerNine[i] = 9*powerNine[i-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t; init();

    while (t--)
    {
        cin >> n;


        vector<int>res;
        for (int i = 15; i >= 0; i--)
        {
            for (int j = 8; j >= 0; j--)
            {
                if (powerNine[i]*j <= n )
                {
                    n -= powerNine[i]*j;
                    if (j < 4)
                        res.push_back(j);
                    else
                        res.push_back(j+1);
                    break;
                }
            }
        }
        bool dont = 1;

        for (auto i : res)
        {
            if (i == 0 && dont)
                continue;
            dont = 0;
            cout << i;
        }
        cout << '\n';
    }


}
