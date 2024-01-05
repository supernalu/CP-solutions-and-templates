#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n, m;

int x[MAXN];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int pom;

        cin >> pom;

        x[pom] = i;
    }

    int res = 1;

    for (int i = 2; i <= n; i++)
    {
        if (x[i] < x[i-1])
            res++; 
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        

        if (x[a] < x[a-1])
        {
            res--;
            cout << 1;
        }
        if (x[a] > x[a+1])
        {
            res--;

            cout << 2;
        }

        if (x[b] < x[b-1])
        {
            res--;
            cout << 3;
        }
        if (x[b] > x[b+1])
        {
            res--;

            cout << 4;
        }

            

        int pom;

        pom = x[a];
        x[a] = x[b];
        x[b] = x[a];

        if (x[a] < x[a-1])
        {
            res++;
            cout << 5;
        }
        if (x[a] > x[a+1])
        {
            res++;
            cout << 6;
        }

        if (x[b] < x[b-1])
        {
            res++;
            cout << 7;
        }
        if (x[b] > x[b+1])
        {
            res++;
            cout << 8;
        }  

        cout << res << endl;
    }



    


}