#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res = 0;
    for (int i = 1; i <= 100; i++)
    {
        string lol, loll; cin >> lol >> loll;
        map<string, int> m;
        m["blue"] = 0;
        m["green"] = 0;
        m["red"] = 0;
        while (true)
        {
            int a;
            string b;
            cin >> a >> b;
            if (b[b.size()-1] != ',' && b[b.size()-1] != ';')
            {
                m[b] = max(m[b], a);
                break;
            }
            m[b.substr(0, b.size()-1)] = max(m[b.substr(0, b.size() - 1)], a);
        }
        res += m["blue"]*m["red"]*m["green"];
    }
    cout << res;
}