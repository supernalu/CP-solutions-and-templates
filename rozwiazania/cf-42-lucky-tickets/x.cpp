#include <bits/stdc++.h>

using namespace std;

int n;

int b[3];

int main()
{
    cin >> n;

    while (n--)
    {
        int a;

        cin >> a;

        b[a%3]++;
    }

    cout << b[0]/2 + min(b[1],b[2]);

}