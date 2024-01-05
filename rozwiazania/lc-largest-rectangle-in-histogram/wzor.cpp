class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        ios_base::sync_with_stdio(0); cout.tie(0);

        constexpr int MAXH = 1e4 + 10;

        constexpr int MAXN = 1e5 + 10;

        int maxh = 0;

        int n = heights.size();

        vector<int> wys[MAXH];

        int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (heights[i] > maxh)
            maxh = heights[i];

        wys[heights[i]].push_back(i);
    }

    set<pair <int, int>> dev;

    vector<int> il(n+10, 0);

    dev.insert({n-1, 0});

    il[n] = 1;

    int q = n;

    for (int i = 1; i <= maxh; i++)
    {
        for (auto j : wys[i-1])
        {
            

            pair<int, int> b = {j, 0};

            auto it = lower_bound(dev.begin(), dev.end(), b);

            pair<int, int> a = *it; 

            

            

            

            int w = a.first - a.second + 1;

            il[w]--;

            dev.erase(a);

            if (a.second <= j-1)
            {
                dev.insert({j-1, a.second});

                il[j - a.second]++;

                
            }
            if (a.first >= j+1)
            {
                dev.insert({a.first, j+1});

                il[a.first - j]++;       
            } 

             

                 
        }  

        
        while (il[q] <= 0)
        {
            q--;   
               
        }

        res = max(res, q*i);
    }

    return res;
        
    }
};