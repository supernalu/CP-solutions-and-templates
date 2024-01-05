#include <bits/stdc++.h>

using namespace std;

int n, h;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> h;
    cin >> s;

    
    int tmp = 0;
    int res = 0;


    for (int i = 0 ; i < n; i++)
    {
        if (s[i] == '(')
            tmp++;
        else
            tmp--;

        if (tmp > h)
        {
            res++;
            tmp-=2;
        }
        else if (tmp < 0)
        {
            res++;
            tmp+=2;
        }
    }

    cout << res;

}