#include <bits/stdc++.h>

using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

// Zwraca liczbę całkowitą z przedziału <L, R>. Każda liczba ma taką samą szansę wystąpienia
long long randInt(long long L, long long R) {
    uniform_int_distribution<long long> dis(L, R);
    return dis(rng);
}

vector<int> w;

long long randWeightedInt(vector<int> weights) {
    discrete_distribution<> dis(weights.begin(), weights.end());
    return dis(rng);
}

int main()
{

    w.push_back(0);

    int n = randInt(1, 20);

    cout << n << endl;

    for (int i = 2; i <= n; i++)
    {
        if (randInt(1, 10) == 1)
        {
            w.push_back(randInt(10, 100));
        }
        else
        {
            w.push_back(randInt(1, 5));
        }


        int a = randInt(1, i-1);

        cout << i << ' ' << a << endl;
    }


}