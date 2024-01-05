#include <bits/stdc++.h>

using namespace std;

int t, m, n;
string s[11];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin >> t;
    
    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            cin >> s[i];
        
        s[0] = s[1];

        string res;

        auto found = [&]() {
            for (int i = 0; i < m; i++)
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    string temp = s[0];
                    temp[i] = ch;
                    
                    auto stringGood = [&]() {
                        for (int j = 1; j <= n; j++)
                        {
                            int badChars = 0;
                            for (int k = 0; k < m; ++k) {
                                if (temp[k] != s[j][k]) {
                                    ++badChars;
                                }
                            }
                            if (badChars > 1) return false;
                        }
                        return true;
                    };

                    if (stringGood()) {
                        res = temp;
                        return true;
                    }
                }
            }
            return false;
        };


        cout << (found() ? res : string("-1")) << '\n'; 

    }
}
