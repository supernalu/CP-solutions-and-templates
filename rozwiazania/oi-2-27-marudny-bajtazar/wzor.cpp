#include <bits/stdc++.h>

#define db 0

using namespace std;

constexpr int MAXN = 1e5 + 10;

constexpr int MAXL = 17;

int n, m;

string a;

unordered_map<string, int> pattern_quan;

int leng_quan[MAXN];

int minn;

set<int> res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    cin >> a;

    int l = a.size();

    for (int i = 0 ; i < n; i++)
    { 
        string tmp = "";

        for (int j = 0; j < MAXL && i + j < n; j++)
        {
            tmp = tmp + a[i+j];

            pattern_quan[tmp]++;

            if (pattern_quan[tmp] == 1)
            {
                leng_quan[j+1]++; 

                if (leng_quan[j+1] == 1)
                {
                    res.insert(j+1);
                }

                if (leng_quan[j+1] == 1 << (j+1))
                {
                    res.erase(j+1);
                }
            }
        }

    }

    cout << *res.begin() << '\n';
    


    for (int q = 0; q < m; q++)
    {
        int t; 

        cin >> t;

        for (int i = max(t - MAXL, 0); i < t; i++)
        {
            string tmp = a.substr(i, t - i-1);

            //cout << tmp << ' '

            for (int j = 0; j < MAXL - t + i && t + j - 1 < n; j++)
            {
                tmp = tmp + a[t+j-1];

                pattern_quan[tmp]--;
                
                if (pattern_quan[tmp] == 0)
                {
                    if (leng_quan[j + t - i] == 1 << (j + t - i))
                    {
                        res.insert(j + t - i);
                    }
                    leng_quan[j+t-i]--;

                    //cout << leng_quan[j+t-i] << ' ' << j + t - i << endl;
                }

                
            }           
        }

        if (a[t-1] == '0')
                a[t-1] = '1';
            else
                a[t-1] = '0';

        for (int i = max(t - MAXL, 0); i < t; i++)
        {
            string tmp = a.substr(i, t - i-1);

            //cout << tmp << ' '

            for (int j = 0; j < MAXL - t + i && t + j - 1 < n; j++)
            {
                tmp = tmp + a[t+j-1];

                pattern_quan[tmp]++;
                
                if (pattern_quan[tmp] == 1)
                {
                    leng_quan[j+t-i]++;

                    if (leng_quan[j + t - i] == 1)
                    {
                        res.insert(j + t - i);
                    }


                    if (leng_quan[j + t - i] == 1 << (j + t - i))
                    {
                        res.erase(j + t - i);
                    }
                }

                
            }           
        }

        cout << *res.begin() << '\n';

        if (db)
        {

            for (int i = 0; i < n; i++)
                cout << a[i] << ' ';

            cout << endl;

            for (int i = 0 ; i < n; i++)
            { 
                string tmp = "";

                for (int j = 0; j < MAXL && i + j < n; j++)
                {
                    tmp = tmp + a[i+j];

                    cout << tmp << ' ';

                    cout << pattern_quan[tmp] << endl;
                }
            }
        }
        
    }
}
