#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int n, s;

vector<pair<int, int>> a;

int main()
{
    cin >> n >> s;  

    for (int i = 0; i < n; i++)
    {
        int b;

        cin >> b;

        a.push_back({b+1, i+1});
    }

    if (n == 1)
    {
        cout << "0\n1";
    }  

    sort(a.begin(), a.end());

    int k = 0;

    vector<int> res;
    vector<int>res2;

    for (auto i : a)
    {
        k += i.first;

        k %= s;

        if (k == s-1)
        {
            k -= i.first;

           res2.push_back(i.second); 
        }
        else
        {
            res.push_back(i.second);
        }
    }

    cout << "0\n";

    for (auto i : res)
    {
        cout << i << ' ';
        
    }

    for (auto i : res2)
    {
        cout << i << ' ';
        
    }






}