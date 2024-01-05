#include <bits/stdc++.h>

using namespace std;

int t;

int n;

string row[2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        cin >> row[0] >> row[1];

        int r = 0; 

        bool res = 1;

        for (int i = 0; i < n; i++)
        {
            if (row[r][i] <= '2')
                continue;

            if (row[(r+1)%2][i] > '2')
            {
                r = (r+1)%2;        
            }
            else
            {
                res = 0;
                break;
            }           
        }

        if (r == 0)
            res = 0;

        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";        
    }
}