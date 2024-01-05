#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

int x[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int pom;

        cin >> pom;

        x[pom] = i;
    }

    int res = 1;

    for (int i = 2; i <= n; i++)
    {
        if (x[i] < x[i-1])
            res++; 
    }

    cout << res;


}