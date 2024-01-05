#include <bits/stdc++.h>

using namespace std;

int n;

struct building
{
    int down;

    int up; 

    int left;

    int right;

    int id;

    building(int a, int b, int c, int d, int e)
    {
        down = b;

        up = d;

        left = a;

        right = c;

        id = e;
    }
};

vector<building> v;

vector<int> sortX;

vector<int> sortY;


bool cmpX(int a, int b)
{
    return v[a].left < v[b].left;
}

bool cmpx (int a, int b)
{
    if (v[a].right == v[b].right)
        return v[a].id < v[b].id;

    return v[a].right < v[b].right;
}

bool cmpY(int a, int b)
{
    return  v[a].down < v[b].down;
}

bool cmpy (int a, int b)
{
    if (v[a].up == v[b].up)
        return v[a].id < v[b].id;

    return v[a].up < v[b].up;
}

int res = 1e9 + 10;


int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        building tmp(a, b, c, d, i);

        v.push_back(tmp);

        sortX.push_back(i-1);

        sortY.push_back(i-1);
    }

    sort(sortX.begin(), sortX.end(), cmpX);

    sort(sortY.begin(), sortY.end(), cmpY);



    int w1 = 0, w2 = 0;

    int s1, s2, s3, s4;

    set<int, decltype(cmpx)*> sX(cmpx);

    int l = 0, r = n;

    for (int i = 0; i <= 17; i++)
    {

        while (w1 < n && v[sortX[w1]].left == i)
        {
            sX.insert(sortX[w1]);
            w1++;  

        }

        


        while (!sX.empty() && v[*(sX.begin())].right + 1 == i)
        {
            //cout << v[*(sX.begin())].id << ' ';

            sX.erase(sX.begin());
            l++;
            r--;

            //cout << v[*(sX.begin())].id << endl;
        }

        

        if (sX.empty())
        {
            //cout << l << ' ' << i << endl;

            set<int, decltype(cmpy)*> sY(cmpy);

            w2 = 0;

            s1 = l;
            s2 = r;

            s3 = 0;
            s4 = 0;

            for (int j = 0; j <= 17; j++)
            {
                //cout << i << ' ' << j <<  endl;

                while (w2 < n && v[sortY[w2]].down == j)
                {
                    sY.insert(sortY[w2]);
                    w2++;
                }

                while (!sY.empty() && v[*(sY.begin())].up+1 == j)
                {
                    //cout << v[*(sY.begin())].id << ' ' << v[*(sY.begin())].right << endl;

                    if (v[*(sY.begin())].right < i)
                    {
                        s3++;
                        s1--;
                    }
                    else
                    {
                        s4++;
                        s2--;
                    }

                    sY.erase(sY.begin());

                     //cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << endl;
                    
                }



                if (sY.empty())
                {
                    res = min(res, max({s1, s2, s3, s4}));

                    //cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << endl;

                }
            }
            //cout << endl;
        }
    }

    cout << res;
}