#include <bits/stdc++.h>

constexpr int INF = 1e9 + 10;
constexpr int LEAVES = 1 << 18;

using namespace std;

int n, q;

vector<int> x(2*LEAVES, INF);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;

    for (int i = LEAVES + 1; i <= LEAVES + n; i++)
    {
        cin >> x[i];
    }

    for (int i = LEAVES - 1; i >= 1; i--)
        x[i] = min(x[i*2], x[i*2 + 1]);
    
    /*
    for (int i = 1; i < 2*LEAVES; i++)
    {
        cout << i << ". " << x[i] << endl;
    }
    */

    for (int w = 0; w < q; w++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if (a == 1)
        {

            int j = LEAVES + b;

            x[j] = c;

            j /= 2;

            for (; j > 0; j /= 2)
            {
                x[j] = min(x[2*j], x[2*j + 1]);              
            }
        }
        else 
        {
            int res = INF;

            b += LEAVES;
            c += LEAVES;

            while (b <= c)
            {
                //cout << b << ' ' << c << endl;

                if (b == c)
                {
                    res = min(x[b], res);
                    // cout << b << ' ' << x[b] << endl;
                    break;
                }

                if (b%2 == 1)
                {
                    res = min(x[b], res);
                    // cout << b << ' ' << x[b] << endl;
                    b++;
                }
                if (c%2 == 0)
                {
                    res = min(x[c], res);
                    // cout << c << ' ' << x[c] << endl;
                    c--;
                }
                
                c /= 2;
                b /= 2;

                
            }
            cout << res << '\n';
        }

    }

    


}