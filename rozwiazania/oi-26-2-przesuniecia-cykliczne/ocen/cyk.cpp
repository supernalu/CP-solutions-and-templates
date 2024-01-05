#include <bits/stdc++.h>
#include "cyklib.hpp"

using namespace std;

int res = 1;

int main()
{
    long long s = circular_shift(0);

    while (circular_shift(1) != s)
    {
        res++;
    }

    give_answer(res);
}