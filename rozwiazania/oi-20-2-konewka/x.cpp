#include <bits/stdc++.h>

constexpr int MAXN = 3e5 + 10;

int siz;
int doj;

int drz[MAXN];

int pref[MAXN];

int res[MAXN];

int pref2[MAXN];

bool fir = 0;

void inicjuj(int n, int k, int *D)
{
    siz = n;

    doj = k;

    for (int i = 0; i < n; i++)
    {
        drz[i+1] = D[i];
    }
}

void podlej(int a, int b)
{
    a++;
    b++;

    fir = 0;

    pref[a]++;

    pref[b+1]--;
}

int dojrzale(int a, int b)
{
    a++;
    b++;

    if (!fir)
    {
        fir = 1;

        for (int i = 1; i <= siz; i++)
        {
            res[i] = res[i-1] + pref[i];
        }

        for (int i = 1; i <= siz; i++)
        {
            res[i] += drz[i];
        }

        for (int i = 1; i <= siz; i++)
        {
            pref2[i] = pref2[i-1];

            if (res[i] >= doj)
            {
                pref2[i] += 1;
            }
        }
    }

    //for (int i = 1; i <= siz; i++)
    //{
        //std::cout << pref2[i]-pref2[i-1] << " ";
    //}

    return (pref2[b]-pref2[a-1]);
}
/*
int main()
{
    int a = 4, b = 6, c[] = {5, 4, 3, 7};

    inicjuj(a, b, c);

    std::cout << dojrzale(2, 3) << std::endl;
    podlej(0, 2);
    std::cout << dojrzale(1, 2) << std::endl;
    podlej(2, 3);
    podlej(0, 1);
    std::cout << dojrzale(0, 3) << std::endl;
}
*/