#include <bits/stdc++.h>

constexpr int INF = 1e9 + 10;

using namespace std;

int n;

vector<int> adj[145];

int dp[40][145];

int parent[40][145];

void readInput() {
    cin >> n;

    string s;
    getline(cin, s);
    
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);

        stringstream ss(s);

        int x;
        while (ss >> x) {
            adj[i].push_back(x);
        }
    }
}

void calculateDp(int startingTemperature) {
    //memset(dp, 1000000010, sizeof dp);
    //memset(parent, 1000000010, sizeof parent);

    
    for (int i = 15; i <= 34; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = INF;
            parent[i][j] = INF;

        }
    }
    

    dp[startingTemperature][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int temp = 15; temp <= 34; temp++)
        {
            for (auto k : adj[i-1]) {
                if (dp[temp-k][i - 1] + abs(k) < dp[temp][i] &&  14 < temp - k && temp - k < 35)
                {
                    dp[temp][i] = dp[temp - k][i - 1] + abs(k);

                    parent[temp][i] = k;
                }
            } 
        }
    }
    /*
    
    for (int temp = 15; temp <= 34; ++temp) {
        cout << temp << ": ";
        for (int i = 0; i <= n; ++i) {
            cout << dp[temp][i] << ' ';
        }
        cout << endl;
    }
    */
}

void retrieveResult() {
    int s = INF, k = INF;

    for (int i = 15; i <= 34; i++)
    {
        //cout << dp[i][n] << endl;
        if (dp[i][n] < s)
        {
            s = dp[i][n];
            k = i;
        }
    }

    if (k == INF)
    {
        cout << "NIE\n";

        return;
    }

    vector<int> res;

    for (int i = n; i > 0; i--)
    {
        //cout << k << endl;

        res.push_back(parent[k][i]);

        k -= parent[k][i];
    }

    reverse(res.begin(), res.end());

    for (auto i : res)
        cout << i << ' ';
    cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    readInput();

    for (int st = 15; st <= 34; st++)
    {
        calculateDp(st);

        retrieveResult();
    }
}

// g++ ... && valgrind ./wzor.exe < in.txt