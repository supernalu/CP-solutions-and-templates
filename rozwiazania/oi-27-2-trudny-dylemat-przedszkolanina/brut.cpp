#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3010;

int n;

//vector<int> primes;

vector<int> deviders[MAXN];

int res;

pair<int, int> cords;

void find_deviders(int a)
{
    for (int i = 1; i*i <= a; i++)
    {
        if(a%i == 0)
        {
            deviders[a].push_back(i);

            if (a/i != i)
                deviders[a].push_back(a/i);
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        find_deviders(i);
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int GCD = __gcd(i, j);

            int tmp = -deviders[GCD].size() + deviders[i].size() + deviders[j].size();

            //cout << i << ' ' << j << ' ' << tmp << endl;

            if (tmp > res)
            {
                res = tmp;

                cords.first = i;
                cords.second = j;
            }
        }
    }

    cout << res << '\n' << cords.first << ' ' << cords.second;

}

/*
            set<int> tmp;

            for (auto k : deviders[i])
            {
                tmp.insert(k);
            }
            for (auto k : deviders[j])
            {
                tmp.insert(k);
            }

            if (tmp.size() > res)
            {
                res = tmp.size();

                cords.first = i;
                cords.second = j;
            }
*/