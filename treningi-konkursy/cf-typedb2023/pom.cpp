#include <bits/stdc++.h>

using namespace std;

map<int, bool> m;

int main()
{
    cout << "{";
    for (int i = 2; i <= 1e9; i++)
    {
        if (m[i] == 1)
            continue;

        cout << i << ", ";

        for (int j = i; j <= 1e9; j+= i)
            m[j] = 1;
    }
}