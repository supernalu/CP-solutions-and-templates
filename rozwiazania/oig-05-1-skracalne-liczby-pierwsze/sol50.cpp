#include <bits/stdc++.h>

using namespace std;

constexpr int MAXB = 1e6 + 10;

int a, b;

bool vis[MAXB];

vector<int> lp;

vector<int> slp;

bool is_slp[MAXB];

void eratos(int b)
{
    for (int i = 2; i <= b; i++)
    {
        if (!vis[i])
        {
            lp.push_back(i);
            vis[i] = 1;

            for (int j = 2*i; j <= b; j += i)
            {
                vis[j] = 1;
            }
        }        
    }
}

int main()
{
    cin >> a >> b;

    eratos(b);

    is_slp[0] = 1;

    for (auto i : lp)
    {       
        if (is_slp[(i - i%10)/10])
        {
            is_slp[i] = 1;
            slp.push_back(i);
        }
    }
    
    /*
    for (auto i : slp)
        cout << i << ' ';
    */

    auto low = lower_bound(slp.begin(), slp.end(), a);
    int lmao = low - slp.begin();
    cout << slp.size() - lmao;

    
    

}