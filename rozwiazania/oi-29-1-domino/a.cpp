#include <bits/stdc++.h>

using namespace std;

long long  m;

vector<long long> fib;

int n = 2;



long long mozna(long long wart)
{ 

    if (wart == m)
        return 1;   

    for (int i = 0; i < fib.size(); ++i)
    { 
        //cout << wart*fib[i]  << ' ';    

        if (m%(wart*fib[i]))
            continue;

        long long t =  mozna(wart*fib[i]);

        //cout << t << ' ';

        if (t)
            return t;
            
    }
    return 0;

}

int main()
{
    cin >> m;

    fib.push_back(1);

    fib.push_back(1);
    
    

    for (int i = 2; fib[i-1] <= m; ++i) 
    {          
        fib.push_back(fib[i-1] + fib[i-2]);   

        cout << fib[i] << ' ';
    }

    reverse(fib.begin(), fib.end());

    cout << mozna(1);
    


}