#include <bits/stdc++.h>

using namespace std;

constexpr int MINN = 5010;

constexpr int MAXN = 1e6 + 10;

int q;

vector<vector<int>> brut(MINN);

int zazdro[MAXN];

int group[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;

    if (q <= 5000)
    {
        brut[1].push_back(2);
        brut[2].push_back(1);

        int j = 3;

        while (q--)
        {
            char c;
            int d;

            cin >> c >> d;

            if (c == 'W')
            {
                brut[d].push_back(j);
                brut[j].push_back(d);

                j++;
            }
            else if (c == 'Z')
            {
                for (auto i : brut[d])
                {
                    brut[i].push_back(j);
                    brut[j].push_back(i);
                }

                j++;
            }
            else
            {
                cout  <<  brut[d].size() << '\n';
            }
        }
    }
    else
    {
        int j = 3;

        zazdro[1] = 1;

        zazdro[2] = 2;

        group[1] = 1;

        group[2] = 1;

        while (q--)
        {
            char c;
            int d;

            cin >> c >> d;

            if (c == 'Z')
            {
                zazdro[j] = zazdro[d];

                group[zazdro[j]]++;

                j++;
            }
            else
            {
                if (zazdro[d] == 1)
                {
                    cout << group[2] << endl;
                }
                else
                {
                    cout << group[1] << endl;
                }
            }
        }
    }


}