#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

char s[MAXN];

int pref[MAXN];

int main()
{
    cin >> s + 1;

    int n = strlen(s + 1);

    //cout << n;

    int ha;

    int il = 0, il2 = 0, il3 = 0;

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            il2++;
        else if (s[i] == ')')
            il3++;
        else
        {
            il++; 
            ha = i;
        }     
    }

    if (il2 < il3 + il)
    {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            pref[i] = pref[i-1] + 1;
        else
        {
            if (i == ha)
            {
                pref[i] = pref[i-1] - il2 + il3 + il - 1;
                if (pref[i] < 0)
                {
                    cout << -1;

                    return 0;
                }
                continue;
            }
            pref[i] = pref[i-1] - 1;        
        }

        //cout << i << endl;

        if (pref[i] < 0)
        {
            cout << -1;

            return 0;
        }
    }



    for (int i = 1; i < il; i++)
        cout << "1\n";  

    cout << il2 - il3 - il + 1;
}