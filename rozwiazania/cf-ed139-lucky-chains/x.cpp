#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e7 + 10;
int t, a, b;
int spf[MAXN];
vector<bool> done(MAXN, 0);


void sieve()
{
    for (int i = 1; i <= MAXN-10; i++)
        spf[i] = i;
    done[1] = 1;
    for (int i = 2; i <= MAXN-10; i++)
    {
        //cout << i << ' ';
        if (done[i])
            continue;
        spf[i] = i;
        done[i] = 1; 
        for (int j = 2*i; j <= MAXN-10; j += i)
        {
            spf[j] = min(spf[j], i);
            done[j] = 1;
        }  
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int c = b-a;
        if (c == 1)
        {
            cout << "-1\n";
            continue;
        }
        int res = MAXN;
        while (c != 1)
        {
            int p = spf[c];
            if (a%p == 0)
                res = 0;
            res = min(res, p-a%p);
            c /= p;
        }
        cout << res << '\n';
    }
}