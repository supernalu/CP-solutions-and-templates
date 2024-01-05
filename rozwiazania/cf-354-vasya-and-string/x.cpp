#include<bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;


int n, k;
char s[MAXN];
int il[2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k >> s+1;

   
    int L = 1, res = 0;

    for (int R = 1; R <= n; R++)
    {
        il[s[R]-'a']++;
        while (min(il[0], il[1]) > k)
        {  
            il[s[L]-'a']--;
            L++;
        }
        res = max(res, R-L+1);
    }
    cout << res;

}