#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 2e9;

vector<long long> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23}; 
map<int, int> divisors;

void generateAntiPrimes(long long number, int lastPrimeIdx, int lastExponent) {
    int newPrime = primes[lastPrimeIdx + 1];
    long long newMultiplier = newPrime;
    for (int i = 1; i <= lastExponent; ++i) {
        if (INF < number * newMultiplier) {
            return;
        }
        divisors[number * newMultiplier] = divisors[number] * (i + 1);
        generateAntiPrimes(number * newMultiplier, lastPrimeIdx + 1, i);
        newMultiplier *= newPrime;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //int n;
    //cin >> n;

    divisors[1] = 1;
    generateAntiPrimes(1, -1, 10000);
    vector<int> antiPrimes;
    int maxDivisors = 0;
    for (auto& [number, noDivisors] : divisors) {
        if (maxDivisors < noDivisors) {
            antiPrimes.push_back(number);
            maxDivisors = noDivisors;
        }
    }
    cout << antiPrimes.size() << '\n' << "{";

    for (auto i : antiPrimes)
        cout << i << ", ";
    cout << "}";

    //cout << *(--upper_bound(antiPrimes.begin(), antiPrimes.end(), n)) << '\n';
}