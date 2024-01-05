#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e3 + 10;

int N, M, k;

int przeszkody[4*MAXN][4*MAXN];

struct Board {
    int n;
    int m;
};

struct Ball {
    int x = M;
    int y = 1;
    int dx = -1;
    int dy = 1;


};

struct Arkanoid {
    Board board;
    Ball ball;
    int pozostale_przeszkody;

    void usun_przeszkode(int h, int x, int y)
    {
        if (przeszkody[x-1][y-1] == k)
            przeszkody[x-1][y-1] = 0;
        if (przeszkody[x+1][y+1] == k)
            przeszkody[x+1][y+1] = 0;
        if (przeszkody[x][y-1] == k)
            przeszkody[x][y-1] = 0;
        if (przeszkody[x-1][y] == k)
            przeszkody[x-1][y] = 0;
        if (przeszkody[x+1][y] == k)
            przeszkody[x+1][y] = 0;
        if (przeszkody[x][y+1] == k)
            przeszkody[x][y+1] = 0;
        if (przeszkody[x+1][y-1] == k)
            przeszkody[x+1][y-1] = 0;
        if (przeszkody[x-1][y+1] == k)
            przeszkody[x-1][y+1] = 0;
    }
    void porusz()
    {
        ball.x = ball.x + ball.dx;
        ball.y = ball.y + ball.dy;
    }
    void zmien_kierunek()
    {
        if ((ball.x == 1 || przeszkody[ball.x-1][ball.y]) && ball.dx == -1)
        {
            //cout << 'k';

            if (przeszkody[ball.x-1][ball.y])
            {
                pozostale_przeszkody--;
                usun_przeszkode(przeszkody[ball.x-1][ball.y], ball.x-1, ball.y);
            }
            ball.dx = 1;
            ball.x--;               
        }
        else if ((ball.x == 2*board.m || przeszkody[ball.x+1][ball.y]) && ball.dx == 1)
        {
            //cout << 'j';

            if (przeszkody[ball.x+1][ball.y])
            {
                pozostale_przeszkody--;
                usun_przeszkode(przeszkody[ball.x+1][ball.y], ball.x+1, ball.y);
            }
            ball.dx = -1;
            ball.x++;
 
        }


        if ((ball.y == 1 || przeszkody[ball.x][ball.y-1]) && ball.dy == -1)
        {
            //cout << 'l';

            if (przeszkody[ball.x][ball.y-1])
            {
                pozostale_przeszkody--;
                usun_przeszkode(przeszkody[ball.x][ball.y-1], ball.x, ball.y+1);
            }
            ball.dy = 1;
            ball.y--;
        }
        else if ((ball.y == 2*board.n || przeszkody[ball.x][ball.y+1]) && ball.dy == 1)
        {
            //cout << 'm';

            if (przeszkody[ball.x][ball.y+1])
            {
                pozostale_przeszkody--;
                usun_przeszkode(przeszkody[ball.x-1][ball.y], ball.x, ball.y+1);
            }
            ball.dy = -1;
            ball.y++;
        }  
    }



    
};

/*
struct Ball {
    pair<int, int> id = {m, 1};
    pair<int, int> wektor = {-1, 1};

    void porusz()
    {
        id = {id.first + wektor.first, id.second + wektor.second};
    }
    void zmien_kierunek()
    {
        
    }
};
*/
Arkanoid ark;

long long solve1()
{
    ark.board.n = N; ark.board.m = M;
    ark.pozostale_przeszkody = k;
    ark.ball.x = M;
    ark.ball.y = 1;
    ark.ball.dx = -1;
    ark.ball.dy = 1;
    
    //read_input
    for (int i = 1; i <= k; i++)
    {
        int a, b;

        cin >> a >> b;

        przeszkody[2*a-1][2*b-1] = i;
        przeszkody[2*a][2*b-1] = i;
        przeszkody[2*a-1][2*b] = i;
        przeszkody[2*a][2*b] = i;
    }

    long long res = 0;

    while(ark.pozostale_przeszkody > 0)
    {
        res++;
        ark.zmien_kierunek();
        ark.porusz();

    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N >> k;

    if (N <= 100 && M <= 100 && k <= 1000)
        cout << solve1();

    
}