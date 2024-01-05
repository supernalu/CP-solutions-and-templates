#include <bits/stdc++.h>

using namespace std;

constexpr int MAXLEN = 210;

int len;

int tab[MAXLEN][MAXLEN];

//vector<tuple<int, int, int>> adj[MAXLEN][MAXLEN];

long long dist[MAXLEN][MAXLEN];

bool done[MAXLEN][MAXLEN];

constexpr long long INF = 1e14;

vector<tuple<int, int, int, int, int>> edgel;
/*
void dijkstra()
{
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

    dist[1][1] = tab[1][1]; 
    pq.push({dist[1][1], 1, 1});

    while (!pq.empty())
    {
        int v1 = get<1>(pq.top()), v2 = get<2>(pq.top());
        pq.pop();

        if (done[v1][v2]) continue;

        done[v1][v2] = true;
        for (auto u: adj[v1][v2])
        {
            if (dist[get<0>(u)][get<1>(u)] > dist[v1][v2] + get<2>(u))  
            {         
                dist[get<0>(u)][get<1>(u)] = dist[v1][v2] +  get<2>(u);
                pq.push({dist[get<0>(u)][get<1>(u)], get<0>(u), get<1>(u)});
            }

            
        }
    }
}
*/

void bellman_ford()
{   
    for (int i = 1; i < len; i++)
    {
        for (auto e: edgel)
        {           

            if  (dist[get<2>(e)][get<3>(e)] > dist[get<0>(e)][get<1>(e)] + get<4>(e))
            {
                dist[get<2>(e)][get<3>(e)] = dist[get<0>(e)][get<1>(e)] + get<4>(e);             
            }
        }
    }
}



int main()
{
    cin >> len;

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= i; j++)
            dist[i][j] = INF;     
    }

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >>  tab[i][j];       
    }

    for (int i = 1; i < len-1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            //adj[i][j].push_back({i+1, j, tab[i+1][j]});
            //adj[i][j].push_back({i+1, j+1, tab[i+1][j+1]});

            edgel.push_back({i, j, i+1, j, tab[i+1][j]});
            edgel.push_back({i, j, i+1, j+1, tab[i+1][j+1]});
        }
    }
    for (int i = 1; i < len-1; i++)
    {
        //adj[len-1][i].push_back({len, 1, min(tab[len][i], tab[len][i+1])});

        edgel.push_back({len-1, i, len, 1, min(tab[len][i], tab[len][i+1])});
    }

    //dijkstra();

    dist[1][1] = tab[1][1];

    bellman_ford();

    cout << dist[len][1];



}
