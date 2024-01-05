#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x; 
pair<int, int> a[200000];

int main()
{
    cin >> n >> x;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a, a + n);
    
    int L = 0, R = n-1;

    while(L != R)
    {
        
        if (a[L].first + a[R].first < x)
        {
            L++;
        }
        else if(a[L].first + a[R].first > x)
        {
            R--;
        }
        else
        {
            cout << a[L].second << ' ' << a[R].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";



}