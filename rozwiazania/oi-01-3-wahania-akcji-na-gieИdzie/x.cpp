#include <bits/stdc++.h>

using namespace std;

struct akcja
{
    int MinVal = 0;
    int ActVal = 0;
    int Res = 0;
};

int n;

list<akcja> gielda;

int res = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;

    while (getline(cin, s))
    {
        stringstream ss{s};
        vector <int> tmp;
        int x;

        while (ss >> x)
        {
            tmp.push_back(x); 
        }
        

        auto id = gielda.begin();

        for (int i = 0; i < tmp.size(); i++)
        {
            if (id == gielda.end())
            {
                akcja t;

                if (tmp[i] == -99)
                    continue;
                

                t.MinVal = min(tmp[i], 0);
                t.ActVal = tmp[i];
                t.Res = t.ActVal - t.MinVal;

                res = max(t.Res, res);

                gielda.push_back(t);

                id = gielda.end();

                continue;
            }

            if (tmp[i] == -99)
            {
                id = gielda.erase(id);

                continue;
            }

            

            (*id).ActVal += tmp[i];
            (*id).MinVal = min((*id).MinVal, (*id).ActVal);
            (*id).Res = max((*id).Res, (*id).ActVal-(*id).MinVal);

            

            res = max(res, (*id).Res);
     
            id++;
        }
    }

    cout << res;
}