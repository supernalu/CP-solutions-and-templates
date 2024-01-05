#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

char a[8*MAXN];

char x[7] = {'0', '0', '0', 'a', 'c', 'k', 'o'};

int main()
{
    cin >> n;

    cin >> a;

    int il = 0;

    for (int i = 0; i <= 8*n-1; i++)
    {
        if (a[i] == '1')
            il++;
    }

    if (il < 3*n || il > 6*n)
    {
        cout << "NIE";
        return 0;
    }
    else 
    {
        int mod = il%n;

        int ws = (il-mod)/n;

        //cout << il << ' ' << mod << ' ' << ws << endl; 

        vector <int> res(n, ws);

        int i = 0;

        while (mod > 0)
        {
            if (res[i] == 6)
                i++;

            res[i]++;
            mod--;       
        }

        for (auto u : res)
        {
            cout << x[u];
        }
    }


    




}