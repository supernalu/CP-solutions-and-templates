#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

int n;

int a[MAXN];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        bool res = 1;

        long long sum = 0;

        for (int i = 1; i <= n; i++)
        {
           cin >> a[i]; 

           sum += a[i];
        }

        sort(a + 1, a + n + 1);

        if (n == 1)
        {
            cout << "YES\n";

            continue;
        }

        int ws = n;

        map<long long, int> il;

        deque<long long> mono;

        mono.push_back(sum);

        il[sum] = 1;

        while (ws > 0)
        {
            if (il[mono.back()] == 0)
            {
                mono.pop_back();

                mono.push_front(0);
            }
            else if (mono.back() > a[ws])
            {
                if (mono.back()%2 == 1)
                {
                    mono.push_front(mono.back()/2 + 1);

                    mono.push_front(mono.back()/2);

                    il[mono.back()/2 + 1] += il[mono.back()];
                    il[mono.back()/2] += il[mono.back()];
                }
                else
                {
                    mono.push_front(mono.back()/2);

                    il[mono.back()/2] += 2*il[mono.back()];
                }

                mono.pop_back();
            }
            else if (a[ws] > mono.back())
            {
                res = 0;
                break;
            }
            else
            {
                il[mono.back()]--;

                ws--;
            }
            
        }
        
        if (res)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }



        




        

    }
}