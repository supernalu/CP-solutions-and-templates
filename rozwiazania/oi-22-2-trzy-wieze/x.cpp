#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

int n;

string s;

int m[3];

bool vis[3];
int suf[MAXN][3];

int res;

int initation()
{
    int k = 1;  int tmp = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i-1])
            tmp++;
        else
            tmp = 1;
        k = max(k, tmp);
    }
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    cin >> s;

    vector<int>s1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            s1.push_back(0);
        else if (s[i] == 'S')
            s1.push_back(1);
        else
            s1.push_back(2);
    }

    
    if (n <= 2500)
    {

        for (int i = 0; i < n-1; i++)
        {
            m[0] = 0;
            m[1] = -1;
            m[2] = -2;

            for (int j = i; j < n; j++)
            {
                if (m[s1[j]] < 0)
                m[s1[j]] = 0;

                m[s1[j]]++;

                if (m[0] != m[2] && m[2] != m[1] && m[0] != m[1])
                {
                    res = max(res, j- i + 1);
                }

                //cout << res << ' ';
            }
        }

        cout << res;
        return 0;
    }
    

    vis[0] = 0; vis[1] = 0; vis[2] = 0;
    suf[n][0] = 0; suf[n][1] = 0; suf[n][2] = 0;

    res = initation();


    for (int i = n-1; i >= 0; i--)
    {
        if (s1[i] == 0)
        {
            suf[i][0] = suf[i+1][0]+1;
            suf[i][1] = suf[i+1][1];
            suf[i][2] = suf[i+1][2];
        }
        else if (s1[i] == 1)
        {
            suf[i][0] = suf[i+1][0];
            suf[i][1] = suf[i+1][1]+1;
            suf[i][2] = suf[i+1][2];
        }
        else
        {
            suf[i][0] = suf[i+1][0];
            suf[i][1] = suf[i+1][1];
            suf[i][2] = suf[i+1][2]+1;
        }
    }
    /*
    for (int i = 0; i <= n; i++)
    {
        cout << suf[i]['B'] << ' ' << suf[i]['C'] << ' ' << suf[i]['S'] << '\n'; 
    }
    */

    for (int i = n-1; i >= 0; i--)
    {
        if (vis[s1[i]])
            continue;
        
        vis[s1[i]] = 1;

        for (int j = i; j >= 0; j--)
        {
            if (suf[j][0] - suf[i+1][0] != suf[j][2] - suf[i+1][2] && 
                suf[j][2] - suf[i+1][2] != suf[j][1] - suf[i+1][1] && 
                suf[j][0] - suf[i+1][0] != suf[j][1] - suf[i+1][1])
            res = max(res, i-j+1);
        }
    }
    cout << res;


}