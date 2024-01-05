#include <bits/stdc++.h>

using namespace std;

int t;

int a, b;

int main()
{
    cin >> t;

    for (int w = 0; w < t; w++)
    {
        cin >> a >> b;

        if (a < 3)
        {
            if (a == 1)
            {
                if (b == 1)
                {
                    cout << 3 << endl;
                }
                else if (b == 0)
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 2 << endl;
                }
            }
            else
            {
                if (b == 1)
                {
                    cout << 2 << endl;
                }
                else if(b == 2)
                {
                    cout << 4 << endl;
                }
                else 
                {
                    cout << 3 << endl;
                }
            }
        }
        else
        {
            int j;

            a--;

            int c;

            if (a%4 == 0)
            {
               c = a; 
            }
            else if (a%4 == 1)
            {
                c = 1;
            }
            else if (a%4 == 2)
            {
                c = a + 1;
            }
            else 
            {
                c = 0;
            }

            a++;

            
            int k = c ^ a;

            //cout << k;

            if (c == b)
            {
                cout << a << endl;
            }
            else if(b == k)
            {
                cout << a + 2 << endl;
            }
            else 
            {
                cout << a + 1 << endl;
            }


        }
        
        
    }
}