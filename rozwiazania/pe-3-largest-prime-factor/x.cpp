#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long i = 2;
    while (i*i <= n) 
        if (n%i == 0)
            n /= i;
        else
            i++;
    cout << n;
}
