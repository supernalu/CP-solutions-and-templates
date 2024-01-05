#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
constexpr int MAXN = 2e5 + 10;

int t, q;
pair<ll, ll> heightRange;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> q;
        heightRange = {1, 5e18};

        while (q--)
        {
            int type;

            cin >> type;

            if (type == 1)
            {
                ll a, b, n;
                cin >> a >> b >> n;

                pair<ll, ll> newHeight = {(a-b)*(n-1)+b+1, (a-b)*n+b};

                if (newHeight.second < heightRange.first || heightRange.second < newHeight.first)
                {
                    cout << 0 << ' ';
                    continue;
                }
                
                heightRange = {max(heightRange.first, newHeight.first), min(heightRange.second, newHeight.second)};
                cout << 1 << ' ';

                //cout << heightRange.first << ' ' << heightRange.second << '\n';
            }
            else
            {
                ll a, b;
                cin >> a >> b;

                ll one = 1;
                ll day1 = (unsigned long long)ceil((long double)(heightRange.second-b)/(a-b));
                ll day2 = max(one, (unsigned long long)ceil((long double)((heightRange.first-b)/(a-b))));
                //cout << heightRange.second << ' ' << a-b << ' ';

                //cout << day1 << ' ' << day2 << ' ';

                if (day1 == day2)
                    cout << day1 << ' ';
                else
                    cout << "-1 ";
            }
        
        }
        cout << '\n';
        
        
    }
}