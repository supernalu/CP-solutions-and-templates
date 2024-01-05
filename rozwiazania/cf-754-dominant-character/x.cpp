#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

bool check(int k)
{
    int L = 0, R = k-1;
    if (R >= n)
        return 0;
    int il[3];
    il[0] = 0; il[1] = 0; il[2] = 0;
    for (int i = 0; i < R; i++)
        il[s[i]-'a']++;
    bool res = 0;
    while (R < n)
    {
        il[s[R]-'a']++;   
        if (il[0] > max(il[1], il[2]))
            res = 1;
        il[s[L]-'a']--;
        L++;
        R++;
         
    }    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> s;

        for (int i = 2; i <= 41; i++)
        {
            if (i == 41)
            {
                cout << "-1\n";
                break;
            }
            if (check(i))
            {
                cout << i << '\n';
                break;
            }
        }
    }
}