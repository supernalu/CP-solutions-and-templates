#include <bits/stdc++.h>

using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

long long randInt(long long L, long long R) {
    uniform_int_distribution<long long> dis(L, R);
    return dis(rng);
}

int main()
{
    cout << randInt(1, 1000) << ' ' << randInt(1, 250) << ' ' <<  randInt(1, 300);
}