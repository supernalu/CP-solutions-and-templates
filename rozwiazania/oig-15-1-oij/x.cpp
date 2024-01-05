#include <bits/stdc++.h>

using namespace std;

int n;

string s;

string pattern = "oij";

int main()
{
    cin >> s;

    n = s.size();

    int j = 0;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == pattern[j])
        {
            if (j == 2)
            {
                j = -1;
                res++;
            }

            j++;
        }
    }

    if (!res)
        cout << "NIE";
    else
        cout << res;
}