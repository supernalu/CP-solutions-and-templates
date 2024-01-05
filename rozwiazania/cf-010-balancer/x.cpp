#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int n;

long long a[MAXN];

long long suma;

vector<int> big;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        suma += a[i];
    }

    suma /= n;


    for (int i = 1; i <= n; i++)
    {
        if (a[i] > suma)
        {
            big.push_back(i);

            //cout << i << ' ';
        }

    }

    int j = 0;

    long long res = 0;

    //cout << suma << endl;

    for (int i = 1; i <= n; i++)
    {
        while (a[i] < suma)
        {
            long long  r = min(suma - a[i], a[big[j]] - suma);

            a[i] += r;

            a[big[j]] -= r;

            res += (abs(big[j]-i))*r;

            //cout << a[big[j]] << ' ';

            if (a[big[j]] == suma)
                j++;
            


        }
    }

    cout << res;


}