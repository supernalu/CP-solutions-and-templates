class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        constexpr int MAXN = 510;
        
        vector<int>dp(MAXN, 0);
        
        dp[0] = arr[0];
        int p = arr[0];
        
        for (int i = 1; i < k; i++)
        {  

            p = max(p, arr[i]);      
    
            dp[i] = p*(i+1);

            //cout << dp[i] << ' ';
        }
        
        for (int i = k; i < n; i++)
        {
        
            for (int w = i-k+1; w <= i; w++)
            {
                int maxi = 0;
                for (int j = w; j <= i; j++)
                {
                    maxi = max(arr[j], maxi);
                }      

                int len = i-w+1;
                dp[i] = max(dp[i], dp[w-1] + len*maxi);

                //cout << dp[i] << ' ';
            }

            //cout << endl;
        }
        
        return dp[n-1];
    }
};