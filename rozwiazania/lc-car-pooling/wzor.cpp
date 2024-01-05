class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        constexpr int MAXN = 1010;
        
        int n = trips.size();
        vector<int> pref(MAXN, 0);
        
        
        for (int i = 0; i < n; i++)
        {
            pref[trips[i][1]] += trips[i][0];
            pref[trips[i][2]] += -trips[i][0];
        }
        
        for (int i = 1; i < MAXN; i++)
        {
            pref[i] += pref[i-1];
        }
        
        for (int i = 0; i < MAXN; i++)
        {
            //cout << pref[i] << ' ';
            if(pref[i] > capacity)
            {           
                return 0;
            }       
        }
        
        return 1;
        
    }
};