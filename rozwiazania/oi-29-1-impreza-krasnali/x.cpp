#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

constexpr int INF = 1e9 + 7;

int n;

int h[MAXN];

int il[MAXN];

vector<int> wh(MAXN, -1);

vector<bool> done(MAXN);

int main()
{

    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];

        il[h[i]]++;

        if (il[h[i]] >= 3)
        {
            cout << 0;

            return 0;
        }     
    }

    wh[0] = n+1;
    wh[n+1] = n+1;

    

    for (int i = 1; i <= n; i++)
    {
        if (done[h[i]])
            continue;

        if (il[h[i]] == 2)
        {
            if (h[i+2] != h[i])
            {
                cout << 0;

                return 0;
            }

            wh[i+1] = h[i];

            done[h[i]] = 1;
            

        }
    }

    
    //preprocesing raczej gitówa
    
    for (int i = 1; i <= n; i++)
    {
        if (wh[i-1]*wh[i+1] < 0)
        {
            

            if (wh[i-1] > 0 and wh[i-1] != h[i])           
                wh[i+1] = h[i];            
            else if (wh[i+1] > 0 and wh[i+1] != h[i])
            {
                wh[i-1] = h[i];   


                for (int j = i-2; j > 0; j-=2)
                {                    
                    if (wh[j-1]*wh[j+1] > 0)
                    {
                        if (wh[j-1] != h[j] and wh[j+1] != h[j])
                        {
                            cout << 0;

                            return 0;
                        }

                        break;
                    }
                    else
                    {
                        if (wh[j+1] > 0 and wh[j+1] != h[j])
                            wh[j-1] = h[j];                        
                        else 
                            break;
                    }
                }
            }      
        }
        else 
        {
            if (wh[i-1] > 0)
            {
                
                if (wh[i-1] != h[i] and wh[i+1] != h[i])
                {
                    cout << 0;

                    return 0;
                }
            }
        }
    }

 
    /*
    for (int i = 1; i <= n; i++)
        cout << wh[i] << ' ';
    */
    

    long long res = 1;

    int j = 1;

    for (int i = 1; i <= n; i++)
    {
        if(il[i] == 0)
        {
            res *= j;

            res %= INF;

            j++;
        }
    }

    //cout << res << endl;

    for (int q = 2; q <= 3; q++)
    {
        int it = 1;

        for (int i = q; i <= n; i += 2)
        {
            if (wh[i-1] == -1 and wh[i+1] == -1)
            {
                it++;
            }
            else
            {               
                res *= it;

                res %= INF;

                it = 1;
            }
        }


            res *= it;

            res %= INF;  


    }

    cout << res;
    
}