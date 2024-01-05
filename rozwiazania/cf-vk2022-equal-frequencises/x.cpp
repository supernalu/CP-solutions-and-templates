#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;
int m['z'-'a'+1];
int k;

bool cmp(int a, int b)
{
    if (abs(k-a) == abs(b-a))
        return a < b;
    reutrn abs(k-a) < abs(b-k);
}

solve()
{

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> s;
        for (int i = 0; i < 26; i++)
            m[i] = 0;
        for(int i = 0; i < n; i++)
            m[s[i]]++;
        int res = 1e9, id;

        for (int i = 1; i*i <= n; i++)
        {
            if (n%i == 0)
            {

            }
        }

    }
}