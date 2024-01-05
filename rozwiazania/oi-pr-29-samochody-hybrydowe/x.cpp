#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

int n, q;

int A, B;

set<int> stacje;

vector<pair<int, int>> query;

vector<pair<int, int>> update;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q >> A >> B;

    for (int i = 1; i <= n; i++)
    {
        int a; 

        cin >> a;

        stacje.insert(a);
    }

    if (n <= 2000 && q <= 2000)
    {
        int res;

        while (q--)
        {
            char type;

            cin >> type;

            int a, b;

            if (type == 'Z')
            {

                cin >> b >> a;

                auto it = stacje.lower_bound(a);

                bool cont = 1;

                int len = *it - b;

                int res = 0;

                int id;

                len = max(0, len - B);

                res += min(B, len);

                if (a < len)
                {
                    cout << a + res << '\n';
                    cont = 0;
                }
                else 
                {
                    a = a - len;

                    id = *it;

                    it++;

                }

                if (cont)
                {

                for ( ; it != stacje.end(); it++)
                {
                    len = *it - id;

                    len = max(len - B, 0);

                    res += min(B, len);

                    if (a < len)
                    {
                        cout << a + res << '\n';
                        cont = 0;
                        break;
                    }
                    else 
                    {
                        a = a - len;

                        id = *it;

                        it++;

                    }
                    
                }

                if (cont)
                {
                    cout << res + B + a << '\n';
                }

            }
            else if (type == 'D')
            {
                           

                cin >> a;

                stacje.insert(a);
            }           
            else
            {

                cin >> a;

                stacje.erase(a);
            }
        }



        return 0;
    }
    }


    /*
    int last_u, first_z;

    for (int i = 0; i < q; i++)
    {
        char type;

        cin >> type;

        switch (type)
        {
            case 'Z':
            
            int a, b;

            cin >> a >> b;

            if (query.empty())
            {
                first_z = i;
            }

            query.push_back({a, b});

            break;

            case 'U':

            int a;

            cin >> a;

            update.push_back({a, -1});

            last_u = i;
        
            break;

            case 'D':

            int a;

            cin >> a;

            update.push_back({a, 1});

            last_u = i;

            break;
        }
    }
   
    if (last_u < first_z)
    {

    }
    */


}