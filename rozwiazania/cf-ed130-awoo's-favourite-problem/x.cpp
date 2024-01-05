//!Dokończyć!!!

#include <bits/stdc++.h>

using namespace std;

int t;

int n;

string s1, s2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> s1 >> s2;

        vector<int> il1(3, 0), il2(3, 0);

        bool res = 1;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] == 'a' && s2[i] == 'c' || s2[i] == 'a' && s1[i] == 'c')
            {
                res = 0;
                break;
            }
            il1[s1[i]-97]++;
            il2[s2[i]-97]++;
        }

        if (!res || il1[0] != il2[0] || il1[1] != il2[1] || il1[1] != il2[1])
        {
            cout << "NO\n";
            continue;
        }

        for(int i = 0; i < n-1; i++)
        {
            if (s1[i] == 'b' && s1[i+1] == 'c' && s2[i] == 'c')
                swap(s1[i], s1[i+1]);
        }

        for(int i = 1; i < n; i++)
        {
            int j = i;

            while (s1[j] == 'b' && s1[j-1] == 'a' && s2[j] == 'a')
            {
                swap(s1[j], s1[j-1]);
                j--;
            }

        }

        cout << s1 << ' ' << s2;

        for(int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                res = 0;
        }

        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";



        
    }


}