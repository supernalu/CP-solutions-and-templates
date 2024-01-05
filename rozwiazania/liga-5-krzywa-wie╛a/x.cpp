#include <bits/stdc++.h>

using namespace std;


int n, d;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> d;
    
    pair<int, int> solvable = {-d, d};

    for (int i = 1; i <= n-1; i++)
    {
        int a; cin >> a;

        solvable.first = max(solvable.first, 2*a-d);
        solvable.second = min(solvable.second, 2*a+d);

        cout << solvable.first << ' ' << solvable.second << '\n';

        if (solvable.first > solvable.second)
        {
            cout << i;
        }
    }


}

