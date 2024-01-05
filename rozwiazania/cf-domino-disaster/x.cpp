#include<bits/stdc++.h>

using namespace std;

int t;

int n;

int main()
{
   cin >> t;

   for (int w = 0; w < t; w++)
   {
       cin >> n;       

       string s;

       cin >> s;

       for (int i = 0; i < n; i++)
       {
            if (s[i] == 'U')
                cout << 'D';
            else if(s[i] == 'D')            
                cout << 'U';        
            else
                cout << s[i];

       }
       cout << endl;
   } 
}