#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

string a[MAXN];

long long ilR[MAXN];

long long  ilW[MAXN];

long long il;

long long res = 1e15;



int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                ilR[i]++;

                ilW[j]++;
                il++;
            } 
        }
    }

    /*
    for (int i = 0; i < n; i++)
    {
        cout << ilR[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << ilW[i] << ' ';
    }
    cout << endl;
    */



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = min(res, 2*il - ilR[i] - ilW[j]);
        }
    }

    cout << res;





}