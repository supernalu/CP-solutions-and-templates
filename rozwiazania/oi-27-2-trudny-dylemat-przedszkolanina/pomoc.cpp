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

int suma;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        find_deviders(i);

        /*
        for (auto j : deviders[i])
        {
            cout << j << ' ';
        } cout << endl;
        */

       suma += deviders[i].size();
    }

    cout << suma / n;
}