//INF279994

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

fstream plik;
fstream output;
int n = 1; 
int arr[210][210];
int sum[210];
int id[210];

bool cmp(int a, int b)
{
    return sum[a] < sum[b];
}

int main()
{
    plik.open("zad1.in");
    output.open("zad1.out");

    while (true)
    {
        plik >> n;

        if (n == 0)
            break;

        output << n << '\n';

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                plik >> arr[i][j]; 
                sum[i] += arr[i][j];
            }
            id[i] = i;
        }

        sort(id+1, id + n+ 1, cmp);

        for (int i = 1; i <= n; i++)
        {
            int act = id[i];

            for (int j = 1; j <= n; j++)
                output << arr[act][j] << ' ';
            output << '\n';
        }
    }

}