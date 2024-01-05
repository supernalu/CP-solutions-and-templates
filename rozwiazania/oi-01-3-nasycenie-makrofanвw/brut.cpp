#include<bits/stdc++.h>
using namespace std;
constexpr int MN=145;
constexpr int R=20;
constexpr int ML=1100000000;
string str;
vector<int> tab[MN];
int dp[MN][R];
int ost[MN][R];
int n;
int main()
{   

    cin>>n;
    
    getline(cin, str);
    for(int x=1; x<n+1; x++)
    {  
        getline(cin, str);
        stringstream ss(str);
        int tmp;
        while (ss >> tmp) {
            tab[x].push_back(tmp);
        }
    }
    for(int i=0; i<MN; i++)
    {
        for(int j=0; j<R; j++)
        {   
            if (i==n) continue;
            dp[i][j]=ML;
        }
    }
    for(int id=n; id>-1; id--)
    {
        for(int j=0; j<R; j++)
        {   
            if (dp[id][j]==ML) continue;
            for(int x: tab[id])
            {   
                if (j-x<0 || j-x>19) continue;
                if (dp[id][j]+abs(x)<dp[id-1][j-x])
                {
                    dp[id-1][j-x]=dp[id][j]+abs(x);
                    ost[id-1][j-x]=x;
                }

            }
        }
    }
    for(int i=0; i<R; i++) 
    {
        int akt=i;
        if (dp[0][i]==ML)
        {
            cout<<"NIE\n";
            continue;

        }
        for(int j=0; j<n; j++)
        {
            cout<<ost[j][akt]<<" ";
            akt+=ost[j][akt];
        }
        cout<<"\n";
    }
}