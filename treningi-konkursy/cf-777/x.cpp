#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;


int t;

int n, m;

vector<bool> is_prime(MAXN, 1);

vector<int>primes;

void sito(int n)
{

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!is_prime[i])
            continue;

        primes.push_back(i);

        for (int j = 2*i; j <= n; j += i)
        {
            is_prime[j] = 0;
        }
    } 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    sito(sqrt(1e9 + 10) + 1);

    while (t--)
    {
        cin >> n >> m;

        int il = 0;

        while (n % m == 0)
        {
            n /= m;

            il++;
        }

        cout << il << ' ';

        if (il == 1)
        {
            cout << "NO\n";
            continue;
        }

        il = 0;

        for (auto i : primes)
        {
            if (i > n)
            {
                break;
            }

            while (n%i == 0)
            {
                il++;
                n /= i;
            }
        }

        cout << il << '\n';


        if (il >= 2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        

    }
}