#include <bits/stdc++.h>

using namespace std;

constexpr int LEAVES = 1<<18;
constexpr int INF = 1e9 + 10;


int n, q;

vector <int> x(2*LEAVES, INF);

int main()
{
    cin >> n >> q;

    for (int i = LEAVES + 1; i <= LEAVES + n; i++)
        cin >> x[i];

    for (int i = LEAVES - 1; i >= 1; i--)
        x[i] = min(x[2*i], x[2*i+1]);

    for (int w = 0; w < q; w++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if (a == 1)
        {
            b += LEAVES;

            x[b] = c;

            b /= 2;

            for (; b >= 1; b /= 2)
                x[b] = min(x[2*b], x[2*b+1]);
           
        }
        else
        {
            b += LEAVES;
            c += LEAVES;

            int res = INF;

            while (b <= c)
            {
                if (b == c)
                {
                    res = min(res, x[b]);
                    break;
                }
                if (b%2 == 1)
                {
                    res = min(res, x[b]);
                    b++;
                }
                if (c%2 == 0)
                {
                    res = min(res, x[c]);
                    c--;
                }

                b /= 2;
                c /= 2;
            }

            cout << res << endl;
        }
    }
    

    
}