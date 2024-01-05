#include <bits/stdc++.h>
#include "zgalib.hpp"

using namespace std;

constexpr int MAXN = 5e5 + 10;

constexpr int INF = 1e9 + 10;

int n;

int diff[20][20];

int d[MAXN];

int res[MAXN];

vector<int> perm;

int main()
{
    n = initialize();

    if (n <= 10)
    {

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            diff[i][j] = get_difference(i, j);
    }

    for (int i = 1; i <= n; i++)
    {
        perm.push_back(i);
    }

    do 
    {
        bool poss = 1;

        for (int i = 1; i <= n; i++)
        {
            int mini = INF;
            int maxi = 0;

            for (int j = i; j <= n; j++)
            {
                mini = min(mini, perm[j-1]);
                maxi = max(maxi, perm[j-1]);

                if (diff[i][j] != maxi - mini)
                    poss = 0;
            }
        }

        if (poss)
        {
            for (int i = 1; i <= n; i++)
            {
                override(i, perm[i-1]);
            }

            if (check_solution())
                return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    }
    else
    {
        res[1] = 1;
       
        d[1] = 0;

        int j = 1;

        for (int i = 2; i <= n; i++)
        {
            d[i] = get_difference(j, i);


            if (d[i] == d[i-1])
            {
                
            }
        }
    }
}