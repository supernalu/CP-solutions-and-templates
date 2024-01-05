#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

vector<vector<int>> trips(MAXN, vector<int>(3, 0));

int capacity;

int n;

int pref[MAXN];

int main()
{
    cin >> capacity;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> trips[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        pref[trips[i][1]] += trips[i][0];
        pref[trips[i][2]] += -trips[i][0];
    }

    for (int i = 1; i < MAXN; i++)
    {
        pref[i] += pref[i-1];
    }

    for (int i = 0; i < MAXN; i++)
    {
        //cout << pref[i] << ' ';
        if(pref[i] > capacity)
        {
            cout << "false";
            return 0;
        }       
    }

    cout << "true";
}