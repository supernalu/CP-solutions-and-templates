#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 10;
int n;
unsigned long long x, il[MAXN]; 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);   
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        il[a]++;
    }
    bool res = 1;
    for (int i = 1; i < x; i++)
    {
        int tmp = il[i]/(i+1);
        il[i] -= tmp*(i+1);
        if (il[i] != 0)
            res = 0;
        il[i+1] += tmp;
    }
    if (il[x] == 0)
        res = 0;
    if (res)
        cout << "Yes";
    else
        cout << "No";
}