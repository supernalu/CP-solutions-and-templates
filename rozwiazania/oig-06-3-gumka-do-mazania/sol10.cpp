#include <bits/stdc++.h> 

using namespace std;

constexpr int MAXN = 1e4 + 5;

int n;



string slowa[MAXN];

bool wys[MAXN][28];

int ile[MAXN][28];

bool not_poss[28];

vector<char> bet[MAXN];

vector<char> resII[MAXN];

int w[MAXN];

vector<char> odp;

int main()
{
    cin >> n;

    if (n == 1)
    {
        string slowo;
        cin >> slowo;

        vector<char> res;
        int min = 0;

        for (int i = slowo.size() - 1; i >= 0; i--)
        {
            if (slowo[i] >= min)
            {
                min = slowo[i];
                res.push_back(min);
            }
        }
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i];
    }
    else 
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> slowa[i];            
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < slowa[i].size(); j++)
            {
                wys[i][int(slowa[i][j]) - 97] = 1;
            }
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                cout << wys[i][j] << ' ';
            }
            cout << endl;
        }
        */
        for (int j = 0; j < 26; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (!wys[i][j])
                {
                    not_poss[j] = 1;
                    break;
                }
            }
        }
        /*
        for (int i = 0; i < 26; i++)
            cout << not_poss[i] << ' ';
        cout << endl;
        */

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < slowa[i].size(); j++)
            {
                if (not_poss[int(slowa[i][j]) - 97] == 0)
                {
                    bet[i].push_back(slowa[i][j]);
                }
            }
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < bet[i].size(); j++)
            {
                cout << bet[i][j];
            }
            cout << endl;
        }
        */
        for (int i = 1; i <= n; i++)
        {
            int min = 0;
            for (int j = bet[i].size() - 1; j >= 0; j--)
            {
                if (bet[i][j] >= min)
                {
                    min = bet[i][j];
                    resII[i].push_back(min);
                }
            }
            /*
            for (int j = resII[i].size() - 1; j >= 0; j--)
                cout << resII[i][j];
            cout << endl;
            */


        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j =  0; j < resII[i].size(); j++)
            {
                ile[i][int(resII[i][j]) - 97]++;
            }
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            for (int j =  0; j < 26; j++)
            {
                cout << ile[i][j] << ' ';
            }
            cout << endl;
        }
        */

        for (int i = 0; i < 26; i++)
        {
            int maximum = 1e8;
            for (int j = 1; j <= n; j++)
            {
                maximum = min(maximum, ile[j][i]);
            }
            for (int j = 0; j < maximum; j++)
            {
                odp.push_back(char(i + 97));
            }
        }
        reverse(odp.begin(), odp.end());
        for (auto i : odp)
            cout << i;

        /*
        int max = resII[1][0];
        int h = 0;
        bool con = 0;
        
        while(!con)
        {
            
            for (int i = 1; i <= n; i++)
            {
                if (w[i] < resII[i].size())
                {
                    while (max > resII[i][w[i]])
                    {
                        w[i]++;
                    }                
                    if(max == resII[i][w[i]])
                    {
                        h++;
                    }
                    else if (max < resII[i][w[i]])
                    {
                        h = 1;
                        max = resII[i][w[i]];
                    }
                    if (h == n)
                    {
                        odp.push_back(resII[i][w[i]]);
                        //cout << resII[i][w[i]];
                        for (int k = 1; k <= n; k++)
                        {
                            if(w[k] < resII[k].size())
                            {
                                w[k]++;
                            }
                            else con = 1;
                        }
                    }
                    //cout << w[i] << ' ';   
                } 
                else con = 1;    
            }
            //cout << endl;                       
        }
        for (int i = odp.size() - 1; i >= 0; i--)
            cout << odp[i];
        */

       
            
    }
}