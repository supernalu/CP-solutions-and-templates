#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;

int x;

string s;

int res;

    cin >> n >> x;

    s = to_string(n);

    cout << s;

    while (s.size() <= n)
    {
        sort(s.begin(), s.end());

        for (int i = s.size()-1; i >= 0; i++)
        {
            int a = x*(s[i]-48);

            if (to_string(a).size() + s.size() <= n)
            {
                s.erase(s.begin()+i);

                s.append(to_string(a));

                res++;

                break;
            }

            if (i == 0)
            {
                cout << -1;

                return 0;
            }
        }
    }





    
}