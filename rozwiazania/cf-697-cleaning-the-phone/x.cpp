#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

int n, m;

int a[MAXN];

int b[MAXN];

bool cmp(int c, int d)
{
        return a[c] < a[d];
}

int main()
{
    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }

        vector<int> w1, w2;

        for (int i = 1; i <= n; i++)
        {
            if (b[i] == 1)
            {
                w1.push_back(i);
            }
            else
            {
                w2.push_back(i);
            } 
        }

        sort(w1.begin(), w1.end(), cmp);

        sort(w2.begin(), w2.end(), cmp);

        int res = 0;

        while (m > 0 && (!w1.empty() || !w2.empty()))
        {
            if (!w1.empty() && m - a[w1.back()] <= 0)
            {
                m -=a[w1.back()];
                res++;
                break;
            }

            //cout << m << ' ';

            if (w1.size() == 1 && w2.empty())
            {
                m -= a[w1.back()];
                res++;

                break;
            }

            //cout << m << ' ';


            if (w2.empty())
            {
                m -= a[w1.back()];

                w1.pop_back();

                res++;

            }
            else if (w1.size() < 2)
            {
                m -= a[w2.back()];

                w2.pop_back();

                res += 2;
            }
            else
            {
                if (a[w1.size()-1] + a[w1.size()-2] > a[w2.back()])
                {
                    m -= (a[w1.size()-1] + a[w1.size()-2]);

                    w1.pop_back();
                    w1.pop_back();
                }
                else
                {
                    m -= a[w2.back()];

                    w2.pop_back();
                }

                          
                res += 2;

                //cout << m << ' ';
            }

            

            

        }
        if (m > 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << res << endl;
        }
    }
}