#include <bits/stdc++.h>

using namespace std;

constexpr int MAXM = 2010;

int m, p, n;

int odw[MAXM][MAXM];

int przek[MAXM][MAXM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> p >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            przek[i][j] = -1;
    

    while (p--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        przek[a][b] = c;
    }

    pair<int,int> pole = {1,1};

    int ruch = 1;

    vector<int> kolorki;
    kolorki.push_back(0);

    odw[1][1] = 1;


    while(n--)
    {
        char a;

        cin >> a;

        if (a == 'P')
        {
            ruch++;
            pole.second++;

            if (przek[pole.first][pole.second] != -1)
            {
                kolorki.push_back(przek[pole.first][pole.second]);
                przek[pole.first][pole.second] = -1;
            }

            odw[pole.first][pole.second] = ruch;

        }
        else if (a == 'L')
        {
            ruch++;
            pole.second--;

            if (przek[pole.first][pole.second] != -1)
            {
                kolorki.push_back(przek[pole.first][pole.second]);
                przek[pole.first][pole.second] = -1;
            }

            odw[pole.first][pole.second] = ruch;

        }
        else if (a == 'G')
        {
            ruch++;
            pole.first--;

            if (przek[pole.first][pole.second] != -1)
            {
                kolorki.push_back(przek[pole.first][pole.second]);
                przek[pole.first][pole.second] = -1;
            }

            odw[pole.first][pole.second] = ruch;

        }
        else if (a == 'D')
        {
            ruch++;
            pole.first++;

            // << "UwU ";

            if (przek[pole.first][pole.second] != -1)
            {
                kolorki.push_back(przek[pole.first][pole.second]);
                przek[pole.first][pole.second] = -1;
            }

            //cout << "UwU ";

            odw[pole.first][pole.second] = ruch;

            //cout << pole.first << ' ' << pole.second << ' ';

        }
        else if (a == 'Z')
        {
            int b, c;

            cin >> b >> c;

            if (odw[b][c] == 0 || odw[b][c] < ruch - kolorki.size()+1)
            {
                cout << "-1\n";
                continue;
            }

            //cout << kolorki.size()-ruch+odw[b][c]-1 << ' ';

            cout << kolorki[kolorki.size()-ruch+odw[b][c]-1] << '\n';
        }
    }







}