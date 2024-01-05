#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> primes; 
vector<bool> vis(500000000, 0);
void sieve()
{
    for (ll i = 3; i < 1e9; i+= 2)
    {
        if (vis[i/2])
            continue;
        //cout << i << ' ';
        vis[i/2] = 1;
        primes.push_back(i);
        for (ll j = i*i; j < 1e9; j += 2*i)
            vis[j/2] = 1;
    }
    cout << "koniec";

}

int main()
{
    sieve();
    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        while (n%2 == 0)
            n /= 2;
        
    }
    
}