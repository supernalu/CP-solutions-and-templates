#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;
constexpr long long INF = 1e18 + 10;

int t, n;
char s[MAXN];
long long val[] = {1, 10, 100, 1000, 10000};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s + 1;
        n = strlen(s+1);
        reverse(s+1, s+n+1);

        vector<vector<long long>> zmiana(n + 1, vector<long long>(5, -INF));
        vector<vector<long long>> bezZmian(n + 1, vector<long long>(5, -INF));
        
        bezZmian[0][0] = 0;

        for (int i = 0; i < n; i++)
        {   
            for (int j = 0; j < 5; j++)
            {
                //cout << s[i+1] << ' ';
                int next = s[i + 1] - 'A';
                if (bezZmian[i][j] != -INF) {
                    bezZmian[i + 1][max(j, next)] = max(bezZmian[i + 1][max(j, next)], bezZmian[i][j] + val[next] * (next >= j ? 1 : -1));
                    for (int k = 0; k < 5; ++k) {
                        zmiana[i + 1][max(k,j)] = max(zmiana[i + 1][max(k,j)], bezZmian[i][j] + val[k]*(k >= j ? 1 : -1));
                    }
                }
                if (zmiana[i][j] != -INF) {
                    zmiana[i + 1][max(j, next)] = max(zmiana[i + 1][max(j, next)], zmiana[i][j] + val[next] * (next >= j ? 1 : -1));
                }

            }
            /*
            for (int j = 0; j < 5; j++)
            {
                cout << (zmiana[i+1][j] == -INF ? "B" : to_string(zmiana[i+1][j])) << ' ';
                cout << (bezZmian[i+1][j] == -INF ? "B" : to_string(bezZmian[i+1][j])) << ' ';
            }
            cout << '\n';
            */
        }


        cout << *max_element(zmiana[n].begin(), zmiana[n].end()) << '\n';
    }
}