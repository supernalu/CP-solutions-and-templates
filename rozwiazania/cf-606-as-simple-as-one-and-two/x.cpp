#include <bits/stdc++.h>

using namespace std;

int t;

int n;

string s;

int main()
{
    cin >> t;

    while(t--)
    {
        cin >> s;

        n = s.size();

        set<int> a;

        for (int i = 0; i < n; i++)
        {
            //cout << s.substr(i, 3) << ' ';

            if (s.substr(i, 3) == "one")
            {
                a.insert(i+1);
            }

            else if (s.substr(i, 3) == "two")
            {
                if (s.substr(i, 5) == "twone")
                {
                    a.insert(i+2);

                    i += 4;
                }
                else
                {
                    a.insert(i+1);
                }
            }
        }

        cout << a.size() << '\n';

        for (auto i : a)
        {
            cout << i+1 << ' ';
        }

        cout << '\n';



        
    }
}