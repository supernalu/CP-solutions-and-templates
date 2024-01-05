#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 4e5 + 10;

int n, a, b;

long long x[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    //cout << "lol";

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];

        x[i] += x[i-1];
    }

    long long res = 0;

    deque<long long> mono;

    for (int i = a; i <= b; i++)
    {
        //cout << i << ' ';

        while (!mono.empty() && x[mono.back()] < x[i])
        {
            mono.pop_back();
        }

        
        mono.push_back(i);
        

        res = x[mono.front()];
    }

    for (int i = 1; i <= n-a; i++)
    {
        //cout << i << ' ';

        

        if (i + a - 1 == mono.front())
        {
            mono.pop_front();
        }
        if (i + b <= n)
        {

        while (!mono.empty() && x[i + b] > x[mono.back()])
        {
            mono.pop_back();
        }
        }

        
        mono.push_back(i+b);
        

        res = max(res, x[mono.front()] - x[i]);

        
        /*
        if (res > 277858080088)
        {
            cout << res << ' ';
        }
        */
        
        
    }

    cout << res;




}