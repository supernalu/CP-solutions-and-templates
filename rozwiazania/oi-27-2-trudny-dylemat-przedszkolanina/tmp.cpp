#include <bits/stdc++.h>
using namespace std;
vector<long long> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};

vector<long long> s;
long long  solve(long long number, int actPrime, int wyk, int lastWyk)
{
    if (number < 0 || number > 1e16)
        return 0;
    s.push_back(number);
    long long res = 1;
    if (actPrime < 21)
        res += solve(number*primes[actPrime+1], actPrime+1, 1, wyk);
    if (wyk < lastWyk)
        res += solve(number*primes[actPrime], actPrime, wyk+1, lastWyk);
    return res;
}

vector<long long> s2;
long long solve2(long long curr, int actPrime, int maxWyk) {
    long long tmp = curr;
    long long res = 0;
    bool czyNieDalo = true;
    for (int i = 1; i <= maxWyk; ++i) {
        tmp *= primes[actPrime];
        if (tmp > 10'000'000'000'000'000LL || tmp < 0) {
            break;
        }
        czyNieDalo = false;
        res += solve2(tmp, actPrime + 1, i);
    }
    if (czyNieDalo) {
        ++res;
        s2.push_back(tmp);
    }
    return res;
}

int main() {

    cout << solve(2, 0, 1, 60) << ' ' << solve2(1, 0, 60);
    
    cout << '\n' << s.size() << ' ' << s2.size() << '\n';


    sort(s.begin(), s.end());
    sort(s2.begin(), s2.end());

    vector<long long> diff;

    // set_difference(s2.begin(), s2.end(), s.begin(), s.end(), back_inserter(diff));

    // for (auto x : diff) {
    //     cout << x << ' ';
    // } cout << '\n';
}