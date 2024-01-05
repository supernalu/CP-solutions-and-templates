#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;
constexpr int INF = 1e7 + 10;

int n;

vector<int> primes;

bool a[INF];

void sito(){
    for (int i = 2; i <= INF; i++)
    {
        if (!a[i])
        {
            primes.push_back(i);
            for (int j = i; j <= INF; j+=i)
                a[j] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    
    sito();

    cin >> n;

    while (n--)
    {
        int x, y;

        cin >> x >> y;

        if (x > y)
            swap(x, y);

        int j = y-x;

        if (j == 1)
        {
            cout << "-1\n";
            continue;
        }

        long long res = 1e9 + 50;

        for (auto i : primes)
        {
            if (i > j)
                break;

            if (j%i == 0)
            {
                long long k = (x+1)*i - x;

                res = min(res, k%i);
            } 
            while (j%i == 0)
            {
                j/= i;
            }
        }

        cout << res << '\n';


        
    }
}