#include <bits/stdc++.h>

using namespace std;

int n;

char p[1000005];

int il[4];

bool poss = true;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 

    
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];

        if (p[i] == '{')
        {
            il[1]++;
        }
        else if (p[i] == '}')
        {
            il[1]--;
            if (il[1] < 0)
            {
            poss = false; 
            }
        }
        else if (p[i] == '[')
        {
            il[2]++;            
        }
        else if (p[i] == ']')
        {
            il[2]--;
            if (il[2] < 0)
            {
            poss = false; 
            }
        }
        else if (p[i] == '(')
        {
            il[3]++;
        }
        else if (p[i] == ')')
        {
            il[3]--;
            if (il[3] < 0)
            {
            poss = false; 
            }
        }        
    }
    if (poss == true)
    {
        int pom = 0;
        for (int i = 1; i < 4; i++)
        {
           if (il[i] == 0)
           {
               pom++;
           }
        }
        if (pom == 3)
        {
            //cout << "TAK" << endl;

            //algorytm tutaj
            stack <int> einz, zwei, drei;
            int stan = 0;
            int max_stan = 1;
            for (int i = 1; i <= n; i++)
            {

                if (p[i] == '{')
                {  
                                         
                    stan++;               
                    einz.push(stan);
                }
                else if (p[i] == '}')
                {
                    if (stan < einz.top()-1)
                    {
                        cout << "NIE"; 
                        return 0;
                    }  
                    stan = einz.top()-1;
                    einz.pop();
                }
                else if (p[i] == '[')
                {
                    stan++;               
                    zwei.push(stan);            
                }
                else if (p[i] == ']')
                {
                    if (stan < zwei.top()-1)
                    {
                        cout << "NIE"; 
                        return 0;
                    }                      
                    stan = zwei.top()-1;
                    zwei.pop();
                    
                }   
                else if (p[i] == '(')
                {
                    stan++;               
                    drei.push(stan);
                }
                else if (p[i] == ')')
                {
                    if (stan < drei.top()-1)
                    {
                        cout << "NIE"; 
                        return 0;
                    }                                       
                    stan = drei.top()-1;
                    drei.pop();
                }
                if (stan > max_stan)
                    max_stan = stan;
                //cout << stan << ' ';
            }
            //cout << endl;
            cout << max_stan;
        }
        else
        {
            cout << "NIE";
        }
    }
    else
    {
        cout << "NIE";
    }


}