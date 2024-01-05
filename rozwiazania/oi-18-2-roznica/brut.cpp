#include <bits/stdc++.h>

using namespace std;

int n;

string s;

int res;

int main()
{
    cin >> n;

    cin >> s;

    for (int i = 0; i < n-1; i++)
    {
        vector<int> v(30, 0);

        int minn = 1e9, maxx = 0;

        for (int j = i; j < n; j++)
        {
            v[s[j] - 97]++;

            for (int k = 0; k < 30; k++)
            {
                //cout << v[k] << ' ';

                if (v[k] != 0)
                {
                    minn = min(minn, v[k]);
                    maxx = max(maxx, v[k]);
                }
            }
            //cout << endl;

            //cout << maxx << ' ' << minn << ", ";

            res = max(res, maxx - minn);

            //cout << maxx - minn << ' ';

            minn = 1e9; maxx = 0;
        }
        //cout << endl;
    }

    cout << res;

}