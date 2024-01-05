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

int main()
{
    cin >> n >> D >> W >> M;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].x >> arr[i].d >> arr[i].w>> arr[i].m;

        //cout << pkt_stycznosci(arr[i]).first << ' ' << pkt_stycznosci(arr[i]).second << '\n';
    }