#include<bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

int t, n;
vector<int> divisors;
vector<int> adj[MAXN];
char color[MAXN];
vector<bool> vis(MAXN);

void initalize()
{
    for (int i = 1; i <= n; i++)
    {
        color[i] = '`';
    }
    divisors.clear();
}

void findDiv(int k)
{
    for (int i = 1; i*i <= k; i++)
    {
        if (k%i != 0)
            continue;

        divisors.push_back(i);
        if (k/i != i)
            divisors.push_back(k/i);
    }
    sort(divisors.begin(), divisors.end());
}




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> t;

    while (t--)
    {
        cin >> n;

        initalize();
        findDiv(n);
        int res;

        for (int i = 0; i < divisors.size(); i++)
        {
            if (divisors[i] + 1 == divisors[i+1])
                continue;
            res = divisors[i]+1;
            break;
        }

        for (int i = 1; i <= n; i++)
            cout << char('a' + i%res);
        cout << '\n';
    }
}