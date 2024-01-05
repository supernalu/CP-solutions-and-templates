#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e6 + 10;

int n, k; 

int a[MAXN];

int id [MAXN];

map<int, int> scale;

vector<int> wys[MAXN];

vector<int> pref[MAXN];

int cop[MAXN];

int res, il, idP, idK;

bool cmp (int c, int b)
{
    return a[c] < a[b];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        cop[i] = a[i];

        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp);

    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[id[i]] != a[id[i-1]])
        {
            scale[a[id[i]]] = j; 
            j++;
        } 
    }

    for (int i = 1; i <= n; i++)
        a[i] = scale[a[i]];


    /*
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    */


    for (int i = 1; i <= n; i ++)
    {
        wys[a[i]].push_back(i);
    }

    for (int i = 0; i < j; i++)
    {
        for (int w = 1; w < wys[i].size(); w++)
        {
            pref[i].push_back(wys[i][w]-wys[i][w-1]-1);
        }
    }

    for (int i = 0; i < j; i++)
    {
        for (int w = 1; w < pref[i].size(); w++)
        {
            pref[i][w] += pref[i][w-1];
        }
    }
    

    for (int i = 0; i < j; i++)
    {
        for (int w = 0; w < pref[i].size(); w++)
        {

        if (pref[i][w] <= k)
        {
            if (w + 2 > il)
            {
                res = pref[i][w];

                il = w + 2;

                idP = wys[i][0];

                idK = wys[i][w+1];

            }  
            else if (w + 2 == il)   
            {
                if (pref[i][0] < res)
                {
                    res = pref[i][w];

                    il = w + 2;

                    idP = wys[i][0];

                    idK = wys[i][w+1]; 
                }
            } 
        }

        }

        int L = 0; int R = 0;
        
        for (R; R < pref[i].size(); R++)
        {    
            //cout << L << ' ' << R << endl;

            while (pref[i][R] - pref[i][L] > k)
            {
                L++;

                //cout << L << ' ' << R << endl;            
            }
            if (pref[i][R] - pref[i][L] <= k)
            {
                if (R - L + 1 > il)
                {
                    res = pref[i][R] - pref[i][L];

                    il = R - L + 1;

                    idP = wys[i][L+1];

                    idK = wys[i][R+1];

                }  
                else if (R - L + 1 == il)   
                {
                    if (pref[i][R] - pref[i][L] < res)
                    {
                        res = pref[i][R] - pref[i][L];

                        il = R - L + 1;

                        idP = wys[i][L+1];

                        idK = wys[i][R+1]; 
                    }
                }           
            }

            //cout  << endl << il << ' ' << res << endl << endl;              
        }

        //cout << endl;
    }

    cout << il << ' ' << res << '\n';

    //cout << idP << ' ' << idK;

    

    for (int i = 1; i <= idP; i++)
    {
        cout << cop[i] << ' ';
    }

    for (int i = idP + 1; i <= idK; i++)
    {
        if (a[i] == a[idP])
            cout << cop[i] << ' ';
    }

    for (int i = idK + 1; i <= n; i++)
    {
            cout << cop[i] << ' ';
    }
    


    
    
    



}