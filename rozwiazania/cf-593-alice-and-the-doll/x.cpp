#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

long long n, m, k;

vector<int> x[MAXN];

vector<int> y[MAXN];

int kierunek = 1;

pair <int, int> poz = {1, 1};

long long res = 1;
long long gr_p, gr_l, gr_g, gr_d;


void sol()
{
    switch (kierunek)
    {
        case 1:

        //cout << 1;
        
        for (auto i : x[poz.first])
        {
            if (i < poz.second)
                continue;

            int q;

            if (i > gr_p)
                q = gr_p;
            else
                q = i;

           

            if (poz.second+1 == q)
            {

                return;
            }

            res = res + q - poz.second - 1;

            poz.second = q-1;

            gr_p = q-1;

            
                
            break;
        }
        break;

        case 2:

        //cout << 2;
        
        for (auto i : y[poz.second])
        {
            if (i < poz.first)
                continue;

            long long q;

            if (i > gr_d)
                q = gr_d;
            else
                q = i;

            if (poz.first+1 == q)
            {
               

                return;
            }

            res = res + q - poz.first - 1;

            poz.first = q-1;

            gr_d = q-1;
                
            break;
        }
        break;

        case 3:

        //cout << 3;

        for (int i = x[poz.first].size() - 1; i >= 0; i--)
        {
            if (x[poz.first][i] > poz.second)
                continue;

            long long q;

            if (x[poz.first][i] < gr_l)
                q = gr_l;
            else
                q = x[poz.first][i];

            if (poz.second-1 == q)
            {
                

                return;
            }

            res = res + poz.second - q - 1;

            poz.second = q+1;

            gr_l = q+1;

            break;
        }

        break;

        case 0:

        //cout << 4;

        for (int i = y[poz.second].size() - 1; i >= 0; i--)
        {
            if (y[poz.second][i] > poz.first)
                continue;

            long long  q;

            if (y[poz.second][i] < gr_g)
                q = gr_g;
            else
                q = y[poz.second][i];

            if (poz.first-1 == q)
            {             

                return;
            }

            res = res + poz.first - q - 1;

            poz.first = q+1;

            gr_g = q+1;

            

            break;
        }

        break;
    }

    kierunek++;

    kierunek %= 4;

    //cout << poz.first << ' ' << poz.second << endl;;

    sol();
}


int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    gr_l = 0; gr_g = 1; gr_d = n+1; gr_p = m+1;

    for (int i = 0; i < k; ++i)
    {
        int a, b;

        cin >> a >> b;

        x[a].push_back(b);

        y[b].push_back(a);
    }

    for (int i = 1; i <= max(n, m); i++)
    {
        x[i].push_back(0);
        x[i].push_back(m+1);

        y[i].push_back(0);
        y[i].push_back(n+1);
    }

    for (int i = 1; i <= max(n,m); i++)
    {
        sort(x[i].begin(), x[i].end());
        sort(y[i].begin(), y[i].end());
    }

    //cout << endl;


    /*
    for (int i = 1; i <= m; i++)
    {
        cout << "x " << i << ": ";

        for (auto u : x[i])
            cout << u << ' ';

        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "y " << i << ": ";

        for (auto u : y[i])
            cout << u << ' ';

        cout << endl;
    }
    */
    
    //cout << endl;

    

    
    sol();

    if (res == 1)
    {
        kierunek = 2;
        sol();
    }

    //cout << res;

    long long h = n*m - k;


    if (res == h)
        cout << "Yes";
    else
        cout << "No";
    
}