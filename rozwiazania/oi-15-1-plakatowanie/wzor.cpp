#include <bits/stdc++.h>

using namespace std;

int n, d, w[250000];

int res;

int main()
{

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//wczytywanie danych

cin >> n;

for (int i = 0; i < n; i++)
{
    cin >> d >> w[i]; 
}
/*
for (int i = 0; i < n; i++)
    cout << w[i];
cout << endl;
*/
//właściwy algorytm O(n)

set <int> s;

for (int i = 0; i < n; i++)
{
    if (s.find(w[i]) == s.end()) 
    {
        res++;

        s.insert(w[i]);
        
    }
    s.erase(s.upper_bound(w[i]), s.end());
    /*
    for (auto it = s.begin(); it != s.end(); ++it)     
        cout << ' ' << *it;
    cout << endl;
    */
}

cout << res;


}