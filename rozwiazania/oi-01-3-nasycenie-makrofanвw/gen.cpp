#include <bits/stdc++.h>

using namespace std;

using ll = long long;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

long long randInt(long long L, long long R) {
    uniform_int_distribution<long long> dis(L, R);
    return dis(rng);
}

int main()
{
    int n = randInt(1, 10);
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << randInt(-3, 3) << endl;
    }

    // int n = randInt(1, 10);
    // cout << n << endl;
    // for (int i = 0; i < n; ++i) {
    //     int tmp = randInt(1, 7);
    //     while (tmp--) {
    //         cout << randInt(-3, 3) << ' ';
    //     }
    //     cout << endl;
    // }

    // int n = randInt(1, 10);
    // cout << n << endl;
    // for (int i = 0; i < n; ++i) {
    //     int tmp = randInt(0, 7);
    //     while (tmp--) {
    //         cout << randInt(-3, 3) << ' ';
    //     }
    //     cout << endl;
    // }


}