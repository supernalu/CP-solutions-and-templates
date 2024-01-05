#include <bits/stdc++.h>

using namespace std;

string a, b;

int main()
{
    cin >> a >> b;


    if (a < b)
        swap(a,b);
    if (a.size() < b.size())
        swap(a, b);
    

    if (a.size() != b.size())
    {
        string c = "";

        for (int i = a.size(); i > b.size(); i--)
        {
            c += '0';
        }

        b =  c + b;
    }

    //cout << a << '\n' << b << '\n';

    int przenoszenie = 0;

    int res[5001];

    for (int i = a.size()-1; i >= 0; i--)
    {
        int tmp = przenoszenie+a[i]+b[i]-48*2;

        res[i+1] = tmp%10;

        przenoszenie = (tmp - tmp%10)/10;

        //cout << tmp << '\n';
    }
    if(przenoszenie > 0)
        cout << przenoszenie;
    for (int i = 1; i <= a.size(); i++)
        cout << res[i];

    return 0;
}