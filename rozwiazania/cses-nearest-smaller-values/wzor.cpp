#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

int a[MAXN];



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    deque<int> mono;

    mono.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        while(a[mono.back()] >= a[i])
        {
            mono.pop_back();
        }

        cout << mono.back() << ' ';

        mono.push_back(i);
    }

}
