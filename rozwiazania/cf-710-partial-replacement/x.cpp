#include<bits/stdc++.h>

using namespace std;

int t;

int n, k;

string s;

int main()
{
    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        cin >> s;

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }



        int st, ko;

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                st = i;
                res++;

                s[i] = 'X';

                break;
            }
        }

        int odl = 1;

        int temp = 0;

        //cout << odl << ' ';


        for (int i = st+1; i < n; i++)
        {
             if (s[i] == '*')
            {
                temp = i;
            }


            if (odl == k )
            {

                if (temp == 0)

                i = temp + 1;

                temp = 0;

                s[i-1] = 'X';

                odl = 1;

                res++;
            }

            odl++;

            //cout << odl << ' ';
        }

        for (int i = n-1; i > 0; i--)
        {
            if (s[i] == '*'){
                res++;
                break;
            }

            if (s[i] == 'X')
                break;


        }


        cout << res << endl;
    }

}