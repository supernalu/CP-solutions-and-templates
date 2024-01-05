#include <bits/stdc++.h>

using namespace std;

string a, b;

int c[30], d[30];

int main()
{
    cin >> a >> b;

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    if (a.size() != b.size())
    {
        cout << "NIE";
        return 0;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            cout << "NIE"; 
            return 0;
        }
    }

    cout << "TAK";

}