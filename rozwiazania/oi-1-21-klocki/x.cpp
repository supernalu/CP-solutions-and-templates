#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, P, K, colors;

int il[MAXN];

int res[MAXN];

int id[MAXN];

bool cmp(int a, int b)
{
    return il[a] > il[b];
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> colors >> P >> K;

    for (int i = 1; i <= colors; i++)
    {
        cin >> il[i];

        id[i] = i;

        n += il[i];
    }
    //cout << n << endl;

    if (n == 1)
    {
        cout << 1;
        
        return 0;
    }
    
    res[1] = P;

    il[P]--;

    res[n] = K;

    il[K]--;

    sort (id + 1, id + colors+ 1, cmp);

    /*
    for (int i = 1; i <= colors; i++)
        cout << id[i] << ' ';
    */

    int start;

    if (res[1] == id[1])
    {
        start = 3;
    }
    else
    {
        start = 2;
    }

    int j = 2;

    for (int i = start; i < n; i += 2)
    {

        res[i] = id[1];

        il[id[1]]--;

        if (il[id[1]] == 0)
        {
            start = i+1;

            //cout << "wtf" << endl;

            if ((id[j] == res[n]) && ((i + 3 + 2*(il[id[j]-1]))%2 == (n-1)%2) && (i + 3 + 2*(il[id[j]-1]) >= n-1))
            {
                start++;
            }
            else if ((id[j] != res[n]) && ((i + 3 + 2*(il[id[j]-1]))%2 == (n-2)%2) && (i + 3 + 2*(il[id[j]-1]) >= n-2))
            {
                start++;
            }

            break;
        }
    }

    //cout << start << endl;
    
    if (il[id[1]] != 0 or res[n-1] == res[n])
    {
        cout << '0';

        return 0;
    }

    /*
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }   cout << endl; */

    for (int i = start; i < n; i+=2)
    {
        if (il[id[j]] == 0)
        {
            j++;

            i--;

            if ((id[j] == res[n]) && ((i + 1 + 2*(il[id[j]-1]))%2 == (n-1)%2) && (i + 1 + 2*(il[id[j]-1]) >= n-1))
            {
                i++;
            }
            else if ((id[j] != res[n]) && ((i + 1 + 2*(il[id[j]-1]))%2 == (n)%2) && (i + 1 + 2*(il[id[j]-1]) >= n))
            {
                i++;
            }
            
        }

        res[i] = id[j];

        il[id[j]]--;
    }


    /*
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }   cout << endl; */
    

    for (int i = 2; i < n; i++)
    {
        if (res[i] == 0)
        {
            if (il[id[j]] == 0)
                j++;
            

            res[i] = id[j];

            if (res[i] == res[i-1] or res[i+1] == res[i])
            {
                cout << 0; 

                return 0;
            }

            il[id[j]]--;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
}