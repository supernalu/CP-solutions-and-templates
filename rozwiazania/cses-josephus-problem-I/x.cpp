#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

queue<int> q;

set<int> s;

int main()
{
    cin >> n;

    if (n == 1)
    {
        cout << '1'; 

        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
   
    int i = 0;

    while(i < n)
    {
        q.push(q.front());
        q.pop();

        cout << q.front() << ' ';
        q.pop();
        i++;
    }
    
    


    
    


}