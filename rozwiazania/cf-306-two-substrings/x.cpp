#include <bits/stdc++.h>

using namespace std;

string s;

int il1, il2, il3;

int main()
{
    cin >> s;

    for (int i = 0; i < s.size()-1; i++)
    {
        //cout << i << ' ';

        if (s.substr(i, 3) == "ABA" || s.substr(i, 3) == "BAB")
        {
            il3++;

            i += 2;
            continue;
        }

        if (s.substr(i, 2) == "AB")
        {
            il1++;
        }
        else if (s.substr(i, 2) == "BA")
        {
            il2++;
        }
   
    }

    //cout << il1 << ' ' << il2 << ' ' << il3 << '\n';

    if (il1 >= 1 && il2 >= 1 || il3 >= 1 && il2 >= 1 || il1 >= 1 && il3 >= 1 || il3 >= 2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    
}