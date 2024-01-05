#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;

int n; 
int a[MAXN];

vector<int> primes;
vector<bool> done(MAXN, 0);

void sieve()
{
    primes.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        if (done[i])
            continue;
        
        done[i] = 1;
        primes.push_back(i);

        for (int j = 2*i; j <= MAXN; j += i)
            done[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    sieve();

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    


    
}