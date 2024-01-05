#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000005;

int n, m;

int p[MAXN];

int max_p;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int pom;
        cin >> pom;

        if (pom <= n)
        {
            p[pom]++;
            if(max_p < p[pom])
            {
               max_p = p[pom];
            } 
        }
        else 
        {
            for (int j = 1; j <= n; j++)
            {
                p[j] = max_p;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << ' ';
    }
}