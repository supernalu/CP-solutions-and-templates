#include <bits/stdc++.h>

constexpr int MAXN = 5e5 + 10;

using namespace std;

int n;

int a[MAXN],  in[MAXN];

long long pref[MAXN];

bool cmp(int c, int b)
{
    return a[c] < a[b];
}

int mini = 1e9 + 10;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        in[i] = i;

        mini = min(mini, a[i]);
    }

    sort(in + 1, in + n + 1, cmp);

    for (int i = 1; i <= n; i++)       
        pref[i] = a[in[i]] + pref[i-1];   

    vector<char>res(n, 'N');

    for (int i = n; i > 1; i--)
    {
        if (a[in[i]] == mini || pref[i] <= a[in[i+1]])
            break;

        res[in[i]-1] = 'T';
    }

    for (auto i : res)
        cout << i;


}