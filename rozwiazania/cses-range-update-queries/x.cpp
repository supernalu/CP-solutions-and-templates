#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;
constexpr int LEAVES = 1<<19;


int n, q;

long long a[MAXN];

vector<long long> x(2*LEAVES);

void lazy(int i)
{
    if (i <= LEAVES)
    {
        x[2*i] += x[i];

        x[2*i+1] += x[i];

        x[i] = 0;
    }
}

int main()
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)   
        cin >> a[i];

    for (int w = 0; w < q; w++)
    {
        int type;

        cin >> type;

        if (type == 2)
        {
            long long r;

            cin >> r;

            long long res = a[r];

            r += LEAVES;

            for (; r >= 1; r /= 2)
                res += x[r];
            

            cout << res << '\n';
        }
        else
        {
            long long c, d, e;

            cin >> c >> d >> e;

            c += LEAVES;
            d += LEAVES;

            while (c <= d)
            {
                if (d == c)
                {
                    x[d] += e;
                    lazy(d);

                    break;
                }
                if (c%2 == 1)
                {
                    x[c] += e;
                    lazy(c);

                    c++;
                }
                if (d%2 == 0)
                {
                    x[d] += e;
                    lazy(d);

                    d--;
                }

                c /= 2;
                d /= 2;
            }
        }

    }
    
}