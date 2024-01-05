#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

struct larry{
    long long x;
    long long d;
    long long w;
    long long m;
};

int n;

long long D, W, M;

larry arr[MAXN];

pair<long long, long long> pkt_stycznosci(larry a)
{
    long long b = (D + a.x)*a.m*M;
    long long c = W*a.m - M*a.w;

    //if (b < 0 || c < 0)
        //cout << "ERROR!\n";

    return {b/__gcd(b,c), c/__gcd(b,c)};
}

bool wieksze(pair<long long, long long> t, larry a)
{
    
    //if (a.w*t.first*M + (a.x-a.d)*t.second*M*a.m < 0)
        //cout << "CODE A\n";
    //if (W*t.first*a.m < 0)
        //cout << W*t.first*a.m << '\n';
        

    //return W*t.first*a.m <= a.w*t.first*M + (a.x-a.d)*t.second*M*a.m;
    __int128_t b = M*a.w - W*a.m;
    __int128_t c = t.first;
    __int128_t d = a.x - a.d;
    __int128_t e = t.second;
    __int128_t g = M;
    __int128_t h = a.m;


    return 0 <= b*c + d*e*g*h;
    //return (0 <= (M*a.w - W*a.m)*t.first + ((a.x-a.d)*t.second*M*a.m));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> D >> W >> M;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].x >> arr[i].d >> arr[i].w>> arr[i].m;

        //cout << pkt_stycznosci(arr[i]).first << ' ' << pkt_stycznosci(arr[i]).second << '\n';
    }

    int res = 1;

    for (int i = 1; i < n; i++)
    {
        pair<long long, long long> tmp = pkt_stycznosci(arr[i]);

        if (wieksze(tmp, arr[i+1]))
            res++;
    }

    cout << res;


}