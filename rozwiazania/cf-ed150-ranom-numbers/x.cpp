#include<bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n;
char s[MAXN];
long long prefCount[MAXN][7], sufCount[MAXN][7];
long long prefres[MAXN], sufRes[MAXN], prefSum[MAXN];
long long power[7];
int last[7];

void initalize()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 7; j++)
            prefCount[i][j] = 0;
    for (int i = n+1; i > 0; i--)
    {
        sufRes[i] = 0;
        prefres[i] = 0;
        prefSum[i] = 0;
        for (int j = 0; j < 7; j++)
            sufCount[i][j] = 0;
    } 

    for (int i = 0; i < 7; i++)
        last[i] = 0;
}
void coount()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 7; j++)
        {
            if (j == s[i]-'A')
                prefCount[i][j] = prefCount[i-1][j]+1;
            else
                prefCount[i][j] = prefCount[i-1][j];
        }
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < 7; j++)
        {
             if (j == s[i]-'A')
                sufCount[i][j] = sufCount[i+1][j]+1;
            else
                sufCount[i][j] = sufCount[i+1][j];
        }
    }    
    for (int i = n; i > 0; i--)
    {
        long long lol = 0;
        for (char j = 'E'; j > s[i]; j--)
        {
            lol = max(lol, sufCount[i+1][j-'A']);
        }

        if (lol == 0)
            sufRes[i] = sufRes[i+1] + power[s[i]-'A'];
        else
            sufRes[i] = sufRes[i+1] - power[s[i]-'A'];

       // cout << sufRes[i] << ' ';
    }

    for (int i = 1; i < n+1; i++)
    {
        prefres[i] = sufRes[1] - sufRes[i+1];
        prefSum[i] = prefSum[i-1] + power[s[i]-'A'];
    }


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    power[0] = 1;
    for (int i = 1; i <= 6; i++)
        power[i] = power[i-1]*10;
    cin >> t;

    while (t--)
    {
        cin >> s + 1;
        n = strlen(s+1);
        initalize();
        coount();

        long long res = sufRes[1];
        for (int i = 1; i <= n; i++)
        {
            sufCount[i][s[i]-'A']--;

            for (int j = 0; j < 5; j++)
            {
                sufCount[i][j]++; 
                long long tmp = sufRes[i+1];

                //*step 1
                long long lol = 0;
                for (char k = 4; k > j; k--)
                {
                    lol = max(lol, sufCount[i+1][k]);
                }

                if (lol == 0)
                    tmp += power[j];
                else
                    tmp -= power[j];
                
                //*step 2  
                int l = 0;
                for (int k = 4; k >= j; k--)
                    l = max(l, last[k]);
                tmp += prefres[i-1];
                tmp = tmp - prefSum[i-1]+prefSum[l];
                l = 0;
                for (int k = 4; k > j; k--)
                    l = max(l, last[k]);

                if (lol == 0 && s[i] > j)
                    tmp = tmp + 2*power[j]*(prefCount[i-1][j] - prefCount[l][j]);
                
                res = max(res, tmp);

                sufCount[i][j]--;

            }
            sufCount[i][s[i]-'A']++;
            last[s[i]-'A'] = i;
        }
        cout << res << '\n';
    }
}