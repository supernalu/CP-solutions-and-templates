#include <bits/stdc++.h>

constexpr int MAXN = 20;

using namespace std;

int n, k;

pair<int, int> zabytek[MAXN];

long long res = 1e18;

int road[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> zabytek[i].first >> zabytek[i].second;
    }

    zabytek[0] = {0, 0};

    zabytek[n+1] = {k, 0};

    vector<int>perm;

    for (int i = 1; i <= n; i++)
        perm.push_back(i);

    do {

        int act = 0;

        int tram = 0;

        long long tmp = 0;

        bool kierunek = 1;

        for (auto i : perm)
        {
            cout << act << ' ' << tram << ' ' <<  i << endl;

            if (tram > act && kierunek == 1)
            {
                kierunek = 0;

                tmp += k - tram;

                tram = k;
            }
            else if (tram < act && kierunek == 0)
            {
                kierunek = 1; 

                tmp += tram;

                tram = 0;
            }

            tmp += abs(tram - act);



            if (act > i && kierunek == 1)
            {
                kierunek = 0;

                tmp += k - act;

                act = k;
            }
            else if (act < i && kierunek == 0)
            {
                kierunek = 1;

                tmp += act;

                act = 0;
            }

            

            tmp += abs(zabytek[i].first - act);

            //tmp += zabytek[i].second;

            int zw = zabytek[i].second;

            act = zabytek[i].first;

            tram = act;

            cout << act << ' ' << tram << ' ' <<  i << endl;

            if (kierunek)
            {
                tmp += min(zabytek[n+1].first - zabytek[i].first, zw);

                zw -= min(zabytek[n+1].first - zabytek[i].first, zw);

                tram += min(zabytek[n+1].first - zabytek[i].first, zw);
            }
            else
            {
                tmp += min(zabytek[i].first - zabytek[0].first, zw);

                zw -= min(zabytek[i].first - zabytek[0].first, zw);

                tram -= min(zabytek[i].first - zabytek[0].first, zw);
            }

            cout << act << ' ' << tram << ' ' <<  i << endl;

            int c = zw/k;

            tmp += c*k;

            if (c%2 == 0)
            {
                if (kierunek == 1)
                {
                    kierunek = 0;
                }
                else
                {
                    kierunek = 1;
                }
            }

            cout << act << ' ' << tram << ' ' <<  i << endl;


            zw %= k;

            tmp += zw;

            if (kierunek)
            {
                tram = zw;
            }
            else
            {
                tram = k - zw;
            }

            cout << act << ' ' << tram << ' ' <<  i << endl;
        



        }

        if (act != 0)
        {
            if (kierunek)
            {
                tmp = tmp + 2*k - act;
            }
            else
            {
                tmp += act;
            }
        }

        cout << endl;

        res = min(res, tmp);

    } while(next_permutation(perm.begin(), perm.end()));



    cout << res;




}