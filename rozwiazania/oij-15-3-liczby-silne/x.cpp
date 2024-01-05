#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int q;

long long fac[16];

set<long long> strong;

unsigned long long pref[MAXN], a[MAXN];

void preprocessing(long long a, int b)
{
    if (b >= 16)
        return;

    if (a + fac[b] < 1e13)
    {
        strong.insert(a + fac[b]);
        preprocessing(a + fac[b], b+1);
    }
    preprocessing(a, b+1);
}

int binSearch(long long b)
{
    int L = 0, R = strong.size();

    int id = strong.size()+1;

    while (L <= R)
    {
        long long mid = (L+R)/2;

        if (a[mid] >= b)
        {
            id = mid;

            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }

    return id;

}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fac[0] = 1;

    for (int i = 1; i <= 20; i++)
    {
        if (fac[i-1]*i > 1e13)
        {
            break;
        }
        
        fac[i] = fac[i-1]*i;
    }

    preprocessing(0, 1);

    //cout << strong.size();

    auto it = strong.begin();

    pref[0] = 0;

    a[0] = 0;

    for (int i = 1; i <= strong.size(); i++)
    {
        pref[i] = pref[i-1] + *it;
        a[i] = *it;

        it++;

        cout << pref[i] << ' ';
    }

    cin >> q;

    while (q--)
    {
        int c, b;
        
        cin >> c >> b;

        //cout << binSearch(c-1) << ' ';

        cout << pref[binSearch(b+1)-1] - pref[binSearch(c)-1] << '\n';
    }
}