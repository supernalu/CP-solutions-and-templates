#include <bits/stdc++.h>
using namespace std;
int a[18], b[18];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int sumA = 0, sumB = 0;
    for (int i = 0; i < 18; i++) {
        cin >> a[i];
        sumA+=a[i];
    }
    for (int i = 0; i < 18; i++) {
        cin >> b[i];
        sumB += b[i];
    }
    if (sumA > sumB) {
        cout << "Algosia";
    }
    else if (sumB > sumA) {
        cout << "Bajtek";
    }
    else {
        sort(a, a+18);
        sort(b, b+18);
        bool diff = 0;
        bool res;
        for (int i = 0; i < 18; i++) {
            if (a[i] > b[i]) {
                res = 0;
                diff = 1;
            }
            else if (a[i] < b[i]) {
                res = 1;
                diff = 1;
            }
        }
        if (!diff) {
            cout << "remis";
        }
        else if (res == 0) {
            cout << "Algosia";
        }
        else {
            cout << "Bajtek";
        }
    }

}