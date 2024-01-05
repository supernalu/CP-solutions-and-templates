#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;

    n--;

    if (n==0)
    {
        cout << '3';
        return 0;
    }

    if (n%3 == 0 )
        cout << 4*(n/3+1); 
    else if (n%3 == 1)
        cout << ((n+2)/3)*4+1;
    else
        cout << (((n+1)/3)*2+1)*2+1;
}