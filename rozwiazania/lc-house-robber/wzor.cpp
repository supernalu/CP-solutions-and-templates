class Solution {
public:
    int rob(vector<int>& nums) {
        constexpr int MAXN = 110;
        
        vector<int> dp(MAXN, 0);
        
        int n = nums.size();
        
        if (n == 1)
        {
            return nums[0];
        }
        
        
        dp[0] = 0;

        dp[1] = nums[0];

        dp[2] = nums[1];
        
        for (int i = 3; i <= n; i++)
        {
            dp[i] = max(dp[i-3], dp[i-2]) + nums[i-1];
            //cout << dp[i] << ' ';
        }
        
        return max(dp[n], dp[n-1]);
    }
};