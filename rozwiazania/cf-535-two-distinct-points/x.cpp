#include <bits/stdc++.h>

using namespace std;

int q;

pair<int,int> a[2];

int main()
{
    cin >> q;

    while (q--)
    {
        cin >> a[0].first >> a[0].second >> a[1].first >> a[1].second;

        if (a[0].first < a[1].first)
        {
            cout << a[0].first << ' ' << a[1].second << endl;
        }
        else
        {
            cout << a[0].second << ' ' << a[1].first << endl;
        }
                    

    }
}