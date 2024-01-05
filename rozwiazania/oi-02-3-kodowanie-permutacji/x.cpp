#include <iostream>
#include <set>
#include<vector>
#include<algorithm>
#include <iterator> 

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

constexpr int MAXN = 3e4 + 10;

int n;

int b[MAXN];

vector<int> res;

ordered_set o_set;

inline int getnum() {
    int chr = getchar_unlocked();
    if (isspace(chr))
        chr = getchar_unlocked();
 
    int a = chr - '0';
    while (isdigit(chr = getchar_unlocked()))
        a = a * 10 + chr - '0';
 
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    n = getnum();

    for (int i = 1; i <= n; ++i)
    {
        b[i] = getnum();
    }

    for (int i = 1; i <= n; ++i)
    {
        o_set.insert(i);
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] >= i)
        {
            cout << "NIE";
            return 0;
        }
    }
    
    for (int i = n; i > 0; --i)
    {
        res.push_back(*(o_set.find_by_order(n-1-b[i])));
        
        o_set.erase(o_set.find_by_order(n-1-b[i]));
        
        n--;    
    }
    
    reverse(res.begin(), res.end());
    
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }      
}