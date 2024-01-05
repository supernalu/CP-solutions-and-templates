#include <bits/stdc++.h>

using namespace std;

int n, k, s;

int a[1003];

bool cmp(int a, int b)
{
    return b < a;
}

int main()
{
    cin >> n >> k >> s;

    int mini = k*s;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort (a + 1, a + (n + 1), cmp);
/*
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
*/
    int sum = 0;
    int i = 1;
    while (sum < mini)
    {
        sum += a[i];
        i++;
    }
    cout << i - 1;
    

}