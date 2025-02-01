#include <bits/stdc++.h>
using namespace std;
string pii = "3141592653589793238462643383279502884197169399375105820974944592307816406286208";
int t;
int n;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if (c%2)
            a++;
        if (a > b)
            cout << "First\n";
        else
            cout << "Second\n";
        
    }

}