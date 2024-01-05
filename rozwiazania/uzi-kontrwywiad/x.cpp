#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100;


int n;
int a[MAXN];

void symulacja(int k)
{
    int act = k;

    for (int i = 1; i <= n; i++)
    {
            int tmp = a[i]-act;
            act += 2*tmp;
    }

    cout << k << ' ' << act << '\n';
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0; i <= 100; i++)
        symulacja(i);

}