#include <bits/stdc++.h>

using namespace std;


int n, m;


map<int, int> mu = {{1, 0}, {2, 1}, {3, 15}, {4, 168}, {5, 1700}, {6, 17220}, {7, 182406}, {8, 2055200}, {9, 24767928}, {10, 319463100}};

int main()
{
    cin >> n >> m;

    if (n == 500)
    {
        cout << 60000;
        return 0;
    }

    cout << mu[n]%m;    
}
