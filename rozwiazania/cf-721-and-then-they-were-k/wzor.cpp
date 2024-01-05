#include <bits/stdc++.h> 

using namespace std;

int t, n;

string s;

int main()
{
    cin >> t;

    for (int w = 0; w < t; w++)
    {
        cin >> n;

        cin >> s;

        int l = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                l++;
        }        

        if (l == 0)
        {
            cout << "DRAW" << endl;
        }
        else if (l%2 == 1 and l != 1)
        {
            cout << "ALICE" << endl;
        }
        else
        {
            cout << "BOB" << endl;
        }
    }
}