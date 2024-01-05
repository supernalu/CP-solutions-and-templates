#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
long long t, n, pos;
char s[MAXN];
int wh[MAXN];
bool erased[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> s + 1 >> pos;
        n = strlen(s+1);
        s[n+1] = 'A';
        for (int i = 1; i <= n; i++)
        {
            wh[i] = i;
            erased[i] = 0;
        }
        long long i, k = -1;
        long long sum = 0;
        for (i = n; sum < pos; i--)
        {
            k++;
            sum += i;
        }
        //cout << k << ' ';
        if (k == 0)
        {
            cout << s[pos];
            continue;
        }
        long long il = 0;
        for (long long j = 2; j <= n+1; j++)
        {
            bool done = 0;
            int act = j-1;
            while (s[act] > s[j] && act > 0)
            {
                il++; //cout << il << ' ';
                erased[act] = 1;
                if (il == k)
                {
                    done = 1;
                    break;
                }
                act = wh[act]-1;
            }
            wh[j] = act+1;
            if (done)
                break;
        }
        /*
        for (int i = 1; i <= n; i++)
            cout << erased[i];
        cout << ' ';
        */
        
        sum -= i;
        pos = pos - sum + 1;
        int tmp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (erased[i])
                continue;
            tmp++;
            if (tmp == pos)
            {
                cout << s[i];
                break;
            }
        }
    }
}