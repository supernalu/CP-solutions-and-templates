//TODO: sprawdzamy połówkowo, znajdujemy pierwszy i ostatni niepasujący, na takim przedziale musimy spermutować, jak dalej nie zgadza się krotność, to musimy napewno "skipnąć" środek, po czy zacząć odejmować w drugich połówkach
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t;
char s[MAXN];
int cou[30];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 30; i++) {
            cou[i] = 0;
        }
        cin >> s+1;
        int n = strlen(s+1);
        int first=-1, last=-1;
        for (int i = 1; i <= n/2; i++) {
            if (s[i]==s[n-i+1])
                continue;
            if (first == -1)
                first = i;
            last = i;
        }
        if (first == -1) {
            cout << "0\n";
            continue;
        }
        int ile = 0;
        for (int i = first; i <= last; i++) {
            cou[s[i]-'a']++;
            cou[s[n-i+1]-'a']--;
        }

    }
}

        /*
        while (l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        if (r <= l) {
            cout << "0\n";
            continue;
        }

        int res = 0;
        do {
            
            cou[0][s[l]-'a']++;
            int moves = 1;
            cou[1][s[r]-'a']++;
            r--;
            while(cou[1][s[l]-'a'] < cou[0][s[l]-'a']) {
                cou[1][s[r]-'a']++;
                r--;
                moves++;
                res++;
            }
            for (int i = 1; i < moves; i++) {
                l++;
                cou[0][s[l]-'a']++;
            }
            l++;
            r--;
        } while(!check());
        cout << res << '\n';
        */