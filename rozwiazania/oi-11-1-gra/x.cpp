#include <bits/stdc++.h>

using namespace std;

map<vector<bool>, bool> dp;
map<vector<bool>, bool> done;

bool gra(vector<bool> game) {
    if (done[game]) {
        return dp[game];
    }
    if (game.back()) {
        done[game] = true;
        return dp[game] = false;
    }
    bool czyDaSiePrzegrana = false;
    for (int i = 0; i < game.size(); ++i) {
        if (game[i]) {
            vector<bool> tmp = game;
            tmp[i] = false;
            int j = i + 1;
            while (tmp[j]) {
                ++j;
            }
            tmp[j] = true;
            czyDaSiePrzegrana = !gra(tmp);
        }
    }
    done[game] = true;
    return dp[game] = czyDaSiePrzegrana;
}

int main()
{
    /*
    int n, k;
    cin >> n >> k;
    int maxx = 0;
    while (k--) {
        int x;
        cin >> x;
        maxx = max(maxx, x);
    }
    if ((n - maxx) % 2 == 0)
        cout << "";
    else
        cout << "";
    */

    
    cout << gra({1, 0, 1, 0, 1, 0, 0});

    // for (auto [vec, val] : dp) {
    //     if (val && vec[vec.size() - 2] == 0) {
    //         cout << '[';
    //         for (int i = 0; i < vec.size(); ++i) {
    //             if (i != 0) cout << ", ";
    //             cout << vec[i];
    //         }
    //         cout << "] " << val << '\n';
    //     }
    // }

    // cout << "\n\n";

    // for (auto [vec, val] : dp) {
    //     if (!val && vec.back() != 1) {
    //         cout << '[';
    //         for (int i = 0; i < vec.size(); ++i) {
    //             if (i != 0) cout << ", ";
    //             cout << vec[i];
    //         }
    //         cout << "] " << val << '\n';
    //     }
    // }
}