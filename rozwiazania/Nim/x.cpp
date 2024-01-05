#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

int n;
vector<int> a;
map<vector<int>, bool> dp;
map<vector<int>, bool> obliczony;

bool solve(vector<int> arr)
{
    if (obliczony[arr]) {
        return dp[arr];
    }
    if (accumulate(arr.begin(), arr.end(), 0) == 0) {
        obliczony[arr] = true;
        return dp[arr] = true;
    }
    bool czyIstniejeRuchDoPrzegrywajacego = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            vector<int> tmp = arr;
            tmp[i] -= j;
            sort(tmp.begin(), tmp.end());
            czyIstniejeRuchDoPrzegrywajacego |= solve(tmp);
        }
    }
    obliczony[arr] = true;
    return dp[arr] = !czyIstniejeRuchDoPrzegrywajacego;
}

int main()
{
    cin >> n; 

    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }

    solve(a);

    for (auto [vec, b] : dp) {
        if (b == 0) continue;
        cout << "[ ";
        for (auto x : vec) {
            cout << x << ' ';
        }
        cout << "] = " << b << '\n';
    }
    

    

}