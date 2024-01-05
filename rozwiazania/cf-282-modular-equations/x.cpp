#include <bits/stdc++.h>

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;

    if (a == b)
    {
        cout << "infinity";
        return 0;
    }

    int n = a - b;

    set <int> x;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i > b)
                x.insert(n/i);
            if (i > b)
                x.insert(i);      
        }
    }

    cout << x.size();
}