#include <bits/stdc++.h>

using namespace std;

int n;

string s;

int res;

vector<int> wh[30];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    cin >> s;

    for (int i = 0; i < n; i++)
    {
        wh[s[i] - 97].push_back(i);
    }   

    for (int k = 0; k < 30; k++)
    {
        for (int j = 0; j < 30; j++)
        {

            if (k != j && !wh[k].empty() && !wh[j].empty())
            {
                vector<int> simp;

                int a = 0, b = 0;

                //cout << wh[k].size() << ' ' << wh[j].size() << endl;
                wh[k].push_back(n+1); wh[j].push_back(n+1);

                for (int i = 0; i < wh[k].size() + wh[j].size(); i++)
                {
                    if (a < wh[k].size() && wh[k][a] < wh[j][b])
                    {
                        simp.push_back(1);
                        a++;
                    }   
                    else if (b < wh[j].size() && wh[k][a] > wh[j][b])
                    {
                        simp.push_back(-1);
                        b++;
                    }

                    //cout << a << ' ' << b << endl; 
                }

                wh[k].pop_back(); wh[j].pop_back();

                /*
                for (auto i : simp)
                    cout << i << ' ';
                cout << endl;
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