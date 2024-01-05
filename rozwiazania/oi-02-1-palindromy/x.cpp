#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9 + 10;

int n;

char s[210];

int isPali[210][210];

int dpMAX[210], dpMIN[210];

int parentMIN[210], parentMAX[210];



bool palindrom(int a, int b)
{
    if ((b-a)%2 == 0)
    {
        return 0;
    }

    for (int i = 0; i <= (b-a+1)/2; i++)
    {
        if (s[a+i] != s[b-i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s+1;

    n = strlen(s+1);

    if (n%2 == 1)
    {
        cout << "NIE";

        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            isPali[i][j] = palindrom(i, j);

            //cout << isPali[i][j] << ' ';
        }

        //cout << '\n';
    }

    dpMAX[0] = 0;

    parentMAX[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dpMIN[i] = INF;
    }

    for (int i = 2; i <= n; i += 2)
    {
        for (int j = 1; j < i; j += 2)
        {   
            if (isPali[j][i] && dpMIN[j-1]+1 < dpMIN[i])
            {
                dpMIN[i] = dpMIN[j-1]+1;

                parentMIN[i] = j;
            }  
        }
    }

    if (dpMIN[n] >= INF)
    {
        cout << "NIE";

        return 0;
    }

    //cout << dpMIN[n] << '\n';

    int k = n;

    vector <int> tmp;

    while(parentMIN[k] != k)
    {
        tmp.push_back(k);

        k = parentMIN[k]-1;
    }

    reverse(tmp.begin(), tmp.end());

    
    k = 0;

    for (int i = 1; i <= n; i++)
    {
        if (tmp[k] < i)
        {
            k++;
            cout << ' ';
        }

        cout << s[i];
    }

    cout << endl;

    dpMAX[0] = 0;

    parentMAX[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dpMAX[i] = -1;
    }

    for (int i = 2; i <= n; i += 2)
    {
        for (int j = 1; j < i; j += 2)
        {   
            if (isPali[j][i] && dpMAX[j-1]+1 > dpMAX[i])
            {
                dpMAX[i] = dpMAX[j-1]+1;

                parentMAX[i] = j;
            }  
        }
    }

    //cout << dpMAX[n] << '\n';

    k = n;

    tmp.clear();

    while(parentMAX[k] != k)
    {
        tmp.push_back(k);

        k = parentMAX[k]-1;
    }

    reverse(tmp.begin(), tmp.end());

    
    k = 0;

    for (int i = 1; i <= n; i++)
    {
        if (tmp[k] < i)
        {
            k++;
            cout << ' ';
        }

        cout << s[i];
    }

    cout << endl;

}