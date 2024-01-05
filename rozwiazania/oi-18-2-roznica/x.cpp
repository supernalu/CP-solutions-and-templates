#include <bits/stdc++.h>

using namespace std;

int n;

string s;

int res;

vector<int> wh[30];

int main()
{
    cin >> n;

    cin >> s;

    for (int i = 0; i < n; i++)
    {
        wh[s[i] - 97].push_back(i);
    }

    /*
    for (int i = 0; i < 30; i++)
        cout << wh[i].size() << ' ';
    */
    

    for (int k = 0; k < 30; k++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (k != j && !wh[k].empty() && !wh[j].empty())
            {
                vector<int> simp;

                for (int i = 0; i < n; i++)
                {
                    if (s[i]-97 == k)
                        simp.push_back(1);
                    else if (s[i]-97 == j)
                        simp.push_back(-1);            
                }

                /*
                for (auto i : simp)
                {
                    cout << i << ' ';
                }   cout << endl;
                */
                

                vector<int> pref_simp;

                pref_simp.push_back(0);

                int q = 0;
                for (auto i : simp)
                {
                    pref_simp.push_back(i + pref_simp[q]);
                    q++;
                }

                int minn = 1e9 + 10;

                int last_a = -1, last_b = -1;

                int l = -1;

                for (int i = 1; i < pref_simp.size(); i++)
                {
                    int r;
                    if (simp[i-1] == 1)
                    {
                        last_a = i;

                        r = last_b;
                    }
                    else if (simp[i-1] == -1)
                    {
                        last_b = i;

                        r = last_a;
                    }

                    for (int j = l + 1; l < r; l++)
                        minn = min(minn, pref_simp[l]);


                    res = max(res, pref_simp[i] - minn);
                }  
            }
        }
    }

    cout << res; 
}