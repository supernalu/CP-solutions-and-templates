#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e3 + 10;

int n;

int a;

int main()
{
    cin >> n;

    long long suma = 0;

    int res = 0;

    multiset<long long> s;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;

        if (a >= 0)
        {
            suma += a;
            res++;
        }
        else
        {
            if (suma + a >= 0)
            {
                res++;
                suma += a;
                s.insert(-a);
            }
            else
            {
                if (s.empty())
                    continue;

                auto it = --s.end();
        
                if (*it <= -a)
                    continue;

                suma += *it + a;

                s.erase(it);

                s.insert(-a);                    

            }
        }

        //cout << suma << ' ';
    }

    cout << res;


}