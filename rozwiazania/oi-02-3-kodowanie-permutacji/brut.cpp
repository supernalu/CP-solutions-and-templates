#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e4 + 10;

int n;

vector<pair<int, int>> b;

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int pom; 
        cin >> pom;

        b.push_back({pom, i});
    }

    for (int k = n; k > 0; k--)
    {

        bool pos = 0;
        /*
        for (auto i: b)
        {
            cout << i.first << ' ' << i.second << endl;   
        }
        cout << endl;
        */
        for (int i = b.size() - 1; i >= 0; i--)
        {                        
            if (b[i].first == 0)
            {
                a[b[i].second] = k;
                //cout << b[i].second << endl;

                for (int j = i + 1; j < n; j++)
                {
                    b[j].first--;
                }

                b.erase(b.begin() + i); 

                pos = 1;    
                break;
        
            }
        }

        if (!pos)
        {
            cout << "NIE";
            return 0;
        }

    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }

    
}