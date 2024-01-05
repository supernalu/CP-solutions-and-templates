#include <bits/stdc++.h>

using namespace std;

char s[10];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    sort(s, s + strlen(s));

    int res =  0;

    vector <string>a;
    do
    {
        res++;
        a.push_back(s);
    }
    while(next_permutation(s, s + strlen(s)));

    cout << res << '\n';
    for (auto i : a)
    {
        cout << i << '\n';
    }

}