#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t, n;

char a[MAXN];



struct aglo {
    int p;
    int k; 

    int dl;

    int sz = 2;

};



bool cmp (aglo a, aglo b)
{
    return a.dl > b.dl;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0); cout.tie(0);

    cin >> t;

    for (int q = 0; q < t; q++)
    {
        cin >> n;

        

        int res = n;

        int b;

        vector<aglo> x;

        cin >> a + 1;

        a[0] = '2'; a[n+1] = '2';

        for (int i = 1; i <= n; i++) 
        {     

            if (a[i] == '0' && a[i-1] != '0')
                b = i-1;
            else if (a[i] != '0'  && a[i-1] == '0')
            {
                x.push_back({});

                x[x.size()-1].p = b;
                x[x.size()-1].k = i;

                x[x.size()-1].dl = i - 1 - b;

                if (a[i] == '2' )
                    x[x.size()-1].sz--;
                if (a[b] == '2')
                    x[x.size()-1].sz--;
                
            }
        }
        if (a[n+1] != '0'  && a[n] == '0')
        {
            x.push_back({});

            x[x.size()-1].p = b;
            x[x.size()-1].k = n+1;

            x[x.size()-1].dl = n  - b;

            if (a[n+1] == '2' )
                x[x.size()-1].sz--;
            if (a[b] == '2')
                x[x.size()-1].sz--;
                
        }


        

        int il = 0;

        if (x.size() == 1 && x[0].sz == 0)
        {
            cout << 0 << endl;

            continue;
        }

        vector <aglo> x1, x2;

        for (auto i : x)
        {
            if (i.sz == 1)
            {
                x1.push_back(i);
            }
            else
            {
                x2.push_back(i);
            }
        }

       sort(x1.begin(), x1.end(), cmp);
       sort(x2.begin(), x2.end(), cmp);


       x1.push_back({0, 0, -1, 1});

       x2.push_back({0, 0, -1, 2});

       int i = 0, j = 0;

        while (max( (x1[i].dl - il), (x2[j].dl - il*2) ) > 0)
        {
            

            if (x1[i].dl + 2 >= x2[j].dl - il && x1[i].dl - il > 0)
            {
                res -= x1[i].dl - il;

                il++; 
                i++;
            }
            else
            {
                res -= max(x2[j].dl - il*2 - 1, 1);

                il += 2;
                j++;
            }
        }
        cout << res << endl;   
    }
}