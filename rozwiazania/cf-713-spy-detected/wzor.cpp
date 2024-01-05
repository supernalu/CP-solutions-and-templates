#include <bits/stdc++.h> 

using namespace std;

constexpr int MAXN = 110;


int t, n;

pair<int, int> a[MAXN];

int main()
{
    cin >> t;

    for (int w = 0; w < t; w++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first;

            a[i].second = i;
        }

        sort (a + 1, a + n + 1);
        
        if (a[1].first != a[2].first)
        {
            cout << a[1].second << endl; 
        }
        else
        {
            cout << a[n].second << endl;
        }


        
    }
}