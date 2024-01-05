#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long ;
int t;
string s;

constexpr ll MOVE = 1e12 + 1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s;
        int n = s.size();

        ll il = 0;


        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                il++;
        
        ll res = il*MOVE, ilOnes = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                il--;
            }
            else
            {
                ilOnes++;
            }

            ll tmp = (il+ilOnes)*MOVE;

            if (i > 0 && s[i] == '0' && s[i-1] == '1')
                tmp--;
            //cout << tmp << ' ';
            res = min(tmp, res);
        }
        cout << res << '\n';
        
    }
}