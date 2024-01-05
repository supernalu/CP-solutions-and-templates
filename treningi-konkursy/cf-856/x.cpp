#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;
constexpr long long MOD = 998244353;

int t;
int n;
int a[MAXN];
int wys[MAXN];

bool isPrime[MAXN];
bool done[MAXN];
long long mod[MAXN];


void sieve()
{
    for (int i = 1; i <= 1e6; i++)
    {
        if (done[i])
            continue;

        isPrime[i] = 1;

        for (int j = i; j <= 1e6; j+=i)
        {
            done[j] = 1;
        }
    }
}

typedef unsigned long long u64;
u64 reverse(u64 a, u64 M) {
    u64 x = 1, y = 0;
    while(1) {
        if(a == 0) return y;
        u64 k = a / M;
        a %= M;
        x -= y * k;
        if(M == 0) return x;
        u64 l = M / a;
        M %= a;
        y -= x * l;
    }
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n; 
    sieve();

    for (int i = 1; i <= 2*n; i++)
    {
        cin >> a[i]; 
        wys[a[i]]++;
    }
    sort (a + 1, a + n + 1);

    int k;
        
    for (int i = 1; i <= 1e6; i++)
    {
        if (wys[i] > 0 && isPrime[i] == 1)
            k++;
    }   

    mod[0] = 1;
    for (int i = 1; i <= 2*n; i++)
        mod[i] = (mod[i-1]*i)%MOD;

    long long res = (mod[n]*mod[n])%MOD;

    res = (res*reverse(mod[k], MOD))%MOD;
    res = (res*reverse(mod[n-k], MOD))%MOD;

    


    
    



}